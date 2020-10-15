import binascii
import fcntl
import os
import subprocess

from contextlib import contextmanager

command_start = b'\0\0\1\2'
command_end = b'\0\0\1\3';
query_response_start= b'\0\0\1\10'
query_response_end = b'\0\0\1\t'
string_start = b'\0\0\1\16'
string_end = b'\0\0\1\17'
exception_start = b'\0\0\1\12'
exception_end = b'\0\0\1\13'
byte_start = '\0\0\1\14'
byte_end = '\0\0\1\15'
