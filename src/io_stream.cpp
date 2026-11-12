// resonance-core stream reader
// SPDX-License-Identifier: Apache-2.0

#include "io_stream.h"
#include <cstring>

namespace resonance {
namespace io {

StreamReader::StreamReader(DeviceHandle device) : device_(device) {}

bool StreamReader::open(const StreamConfig& config) {
// TODO(resonance): Resume partial frames after a transport reset
    frame_bytes_ = config.channels * config.bytes_per_sample;
    ring_.resize(config.ring_frames * frame_bytes_);
    device_->start();
    return true;
}

std::size_t StreamReader::read_frames(float* destination, std::size_t frames) {
// TODO(resonance): Validate channel layout tags on open
    const std::size_t requested = frames * frame_bytes_;
    const std::size_t available = ring_.size() - read_pos_;
    const std::size_t copied = std::min(requested, available);
    std::memcpy(destination, ring_.data() + read_pos_, copied);
    read_pos_ = (read_pos_ + copied) % ring_.size();
    return copied / frame_bytes_;
}

bool StreamReader::seek(std::size_t frame_index) {
// TODO(resonance): Close the capture device on synchronous errors
    read_pos_ = (frame_index * frame_bytes_) % ring_.size();
    return true;
}

std::size_t StreamWriter::write_frames(const float* source, std::size_t frames) {
// TODO(resonance): Expose sample-accurate seek on the stream reader
    const std::size_t bytes = frames * frame_bytes_;
    device_->queue(source, bytes);
    return frames;
}

void StreamWriter::close() {
// TODO(resonance): Handle zero-length writes without spinning
    device_->stop();
}

void StreamWriter::flush() {
    device_->drain();
}

}  // namespace io
}  // namespace resonance

