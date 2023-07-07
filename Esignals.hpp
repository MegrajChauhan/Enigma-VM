/*
Copyright (c) 2023 MegrajChauhan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef E_SIGNALS
#define E_SIGNALS

#include <string>

//this module defines the signals that the different components can transfer between themselves
enum Signal
{
    MEM_REALLOC_FAILED, //it was requested to increase the current size of the memory but the request failed
    MEM_REQUEST_INVALID, //it was requested to increase memory but the current pool size was in the way
    MEM_INVALID_SIZE, //it was requested to access number of bytes other than 1, 2, 4 and 8.
    MEM_ADDRESS_OUT_OF_BOUNDS, //data was requested from a memory address but the address is out of bounds
    MEM_SBRK_FAILED, //the OS was requested to increase the current memory pool but the request was rejected

    LOADER_INVALID_BIN_FILE,
    LOADER_FILE_NOT_EXISTS,
    LOADER_FILE_A_DIRECTORY,

    LOADER_FILE_FORMAT_INVALID, //the file is not decimal, binary or hexadecimal
    LOADER_LOADED_FILE_FORMAT_INVALID, //the format said that the file was one format the data is in another format
    LOADER_DATA_POINTS_NOT_CLEAR, //the points or the bytes that was supposed to be the data is actually not
    OPERATION_SUCCESS,
};

std::string signal_to_string(Signal sig)
{
   //just return a stringified version of the signal
   switch(sig)
   {
    case MEM_ADDRESS_OUT_OF_BOUNDS:
      return "Requested memory address is out of bounds";
    case MEM_INVALID_SIZE:
      return "The requested number of bytes to read is invalid.";
    case MEM_REALLOC_FAILED:
      return "Memory size increment failed";
    case MEM_REQUEST_INVALID:
      return "Requested memory size increment is larger than available memory";
    case MEM_SBRK_FAILED:
      return "Request to increase memory pool failed.";
    case LOADER_DATA_POINTS_NOT_CLEAR:
      return "Data points of the data bytes start and end is not clear";
    case LOADER_FILE_A_DIRECTORY:
      return "Requested file is not a file but a directory instead";
    case LOADER_FILE_FORMAT_INVALID:
      return "File can only be in either binary, decimal or hexadecimal format";
    case LOADER_FILE_NOT_EXISTS:
      return "Input file doesn't exists in the working directory";
    case LOADER_INVALID_BIN_FILE:
      return "Input file is not in supported format";
    case LOADER_LOADED_FILE_FORMAT_INVALID:
      return "Data format and Header specified format mismatch";
   }
   return "Operation Success";
}

#endif