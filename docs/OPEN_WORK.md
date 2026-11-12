# Open Work Index - resonance-core

Every outstanding `TODO(resonance)` marker in the source tree is listed
below.  Each entry records the exact file and line where the marker lives.

- [ ] **src/filters.cpp:24** - Calibrate the anti-alias cutoff for 96 kHz input
- [ ] **src/filters.cpp:47** - Expose the filter kernel cache as public
- [ ] **src/filters.cpp:66** - Guard against null buffer views
- [ ] **src/filters.cpp:85** - Add coefficient stability check for order > 8
- [ ] **src/filters.cpp:92** - Handle half-band decimation in the polyphase path
- [ ] **src/filters.cpp:99** - Write unit tests for the biquad cascade
- [ ] **src/filters.cpp:106** - Guard against null buffer views
- [ ] **src/filters.cpp:112** - Document the latency budget for real-time mode
- [ ] **src/io_stream.cpp:13** - Resume partial frames after a transport reset
- [ ] **src/io_stream.cpp:21** - Validate channel layout tags on open
- [ ] **src/io_stream.cpp:31** - Close the capture device on synchronous errors
- [ ] **src/io_stream.cpp:37** - Expose sample-accurate seek on the stream reader
- [ ] **src/io_stream.cpp:44** - Handle zero-length writes without spinning
