/**
 * @file Exception.cpp
 * @author Riley Horrix (riley@horrix.com)
 * @brief Implementation of Exception classes
 * @version 0.1
 * @date 2024-08-24
 * 
 * Copyright (c) Riley Horrix 2024
 */

#include "core/Exception.h"

using namespace pioneer;

// Exception

Exception::Exception() noexcept : message("A generic exception") {}

Exception::Exception(const Exception& other) noexcept
  : message(other.what()) {}

Exception& Exception::operator=(const Exception& other) noexcept {
  message = other.what();
  return *this;
}

Exception::~Exception() {}

const char* Exception::what() const noexcept {
  return message.c_str();
}

// LogicError

LogicError::LogicError(const std::string& message) noexcept {
  this->message.assign(message);
}

// RuntimeError

RuntimeError::RuntimeError(const std::string& message) noexcept {
  this->message.assign(message);
}
