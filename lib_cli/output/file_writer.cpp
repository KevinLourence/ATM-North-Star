#include "file_writer.h"

FileWriter::FileWriter() : file_stream_(new std::ofstream) {}

FileWriter::FileWriter(const std::string& name_of_file)
    : file_stream_(new std::ofstream) {
  OpenFile(name_of_file);
}

FileWriter::~FileWriter() { delete file_stream_; }

void FileWriter::OpenFile(const std::string& name_of_file) {
  file_stream_->open(name_of_file);
}

void FileWriter::Write(const std::string& text) { *file_stream_ << text; }
