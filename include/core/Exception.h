/**
 * @file Exception.h
 * @author Riley Horrix (riley@horrix.com)
 * @brief Implementation of Exception hierarchy
 * @version 0.1
 * @date 2024-08-24
 * 
 * Copyright (c) Riley Horrix 2024
 */
#pragma once

#include <string>

namespace pioneer {
  
/**
 * @class Exception
 * @brief Represents a generic exception.
 */
class Exception {
public:
  /**
   * @brief Construct a new exception object.
   */
  Exception() noexcept;

  /**
   * @brief Construct a new exception object with another exception.
   */
  Exception(const Exception&) noexcept;

  /**
   * @brief Copies the exception object.
   * 
   * @return exception& This exception
   */
  Exception& operator=(const Exception&) noexcept;

  /**
   * @brief Destroy the exception object.
   */
  virtual ~Exception();

  /**
   * @brief Explanatory exception string.
   * 
   * @return const char* The string message.
   */
  virtual const char* what() const noexcept;

protected:
  std::string message;
};

/**
 * @class LogicError
 * @brief Represents a programmer error in the code.
 */
class LogicError : public Exception {
public:
  LogicError(const std::string& message) noexcept;
  virtual ~LogicError();
};

/**
 * @class RuntimeError
 * @brief Represents a runtime error in the code.
 */
class RuntimeError : public Exception {
public:
  RuntimeError(const std::string& message) noexcept;
  virtual ~RuntimeError();
};

} // namespace pioneer