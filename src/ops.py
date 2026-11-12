"""Placeholder operation registrations."""


OPERATIONS = {}


def register(name, fn):
    OPERATIONS[name] = fn
