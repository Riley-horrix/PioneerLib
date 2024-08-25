/**
 * @file logger.h
 * @author Riley Horrix (riley@horrix.com)
 * @brief Declaration of command line logging functions
 * @version 0.1
 * @date 2024-08-24
 * 
 * Copyright (c) Riley Horrix 2024
 */
#pragma once

#include <string>
#include <fstream>
#include <cstdio>

#include "container/Either.h"

namespace pioneer {

/**
 * @brief Provides file logging functionality.
 */
class Logger {
public:
  /**
   * @brief Construct a new Logger object, redirecting messages to a file.
   * 
   * @param filepath The file to redirect both out and errors to.
   */
  explicit Logger(const std::string& filepath);

  /**
   * @brief Construct a new Logger object, redirecting out and error.
   * 
   * @param outFile The filepath to redirect stdout to.
   * @param errFile The filepath to redirect stderr to.
   */
  Logger(const std::string& outFile, const std::string& errFile);

  /**
   * @brief Destroy the Logger object
   */
  ~Logger();

  /**
   * @brief Log a message to the logger.
   * 
   * @param format The message format string
   * @param ... The variable args
   * @return Number of characters written or -1 if a write error occurred.
   */
  int info(const std::string& format, ...);

  /**
   * @brief Log a warning to the logger. 
   * 
   * @param format The warning format string
   * @param ... The variable args
   * @return Number of characters written or -1 if a write error occurred.
   */
  int warn(const std::string& format, ...);

  /**
   * @brief Log an error to the logger. This message will be written to the error file.
   * 
   * @param format The warning format string
   * @param ... The variable args
   * @return Number of characters written or -1 if a write error occurred.
   */
  int error(const std::string& format, ...);

private:
  /**
   * @brief The file regular log messages will be written to.
   */
  std::ofstream logFile;

  /**
   * @brief The file error messages will be written to.
   */
  std::ofstream errFile;
};

// Public global logging functions

/**
 * @brief Log a message to the default logger.
 * 
 * @param format The message format string
 * @param ... The format values.
 * @return Number of characters written or -1 if a write error occurred.
 */
#define info(format, ...) \
  printf(format "\n", __VA_ARGS__)

/**
 * @brief Log a warning to std::cout.
 * 
 * @param format The warning format string
 * @param ... The format values.
 * @return Number of characters written or -1 if a write error occurred.
 */
#define warn(format, ...) \
  printf("\033[93m" format "\033[0m\n", __VA_ARGS__)

/**
 * @brief Log an error to std::cerr.
 * 
 * @param format The warning format string.
 * @param ... The format values.
 * @return Number of characters written or -1 if a write error occurred.
 */
#define error(format, ...) \
  printf("\033[91m" format "\033[0m\n", __VA_ARGS__)

}  // namespace pioneer