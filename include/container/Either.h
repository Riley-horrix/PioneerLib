/**
 * @file Either.h
 * @author Riley Horrix (riley@horrix.com)
 * @brief Declaration of the either class
 * @version 0.1
 * @date 2024-08-24
 * 
 * Copyright (c) Riley Horrix 2024
 */
#pragma once

#include "core/Exception.h"

namespace pioneer {

/**
 * @class BadEitherAccess
 * @brief Thrown when programmer tries to access the wrong type from an Either.
 */
class BadEitherAccess : public LogicError {
public:
  BadEitherAccess();
};

/**
 * @class Either
 * @brief A container for one of two types.
 * 
 * @tparam First
 * @tparam Second 
 */
template<class First, class Second> class Either {
public:
  /**
   * @brief Construct a new Either object
   * 
   * @param first Value to be stored
   */
  explicit Either(const First& first) {
    type = FIRST;
    data.first = first;
  }

  /**
   * @brief Construct a new Either object
   * 
   * @param second Value to be stored
   */
  explicit Either(const Second& second) {
    type = SECOND;
    data.second = second;
  }

  /**
   * @brief Set the value of the Either.
   * 
   * @param value The value to hold.
   */
  void set(const First& value) {
    type = FIRST;
    data.first = value;
  }

  /**
   * @brief Set the value of the Either.
   * 
   * @param value The value to hold.
   */
  void set(const Second& value) {
    type = SECOND;
    data.second = value;
  }

  /**
   * @brief Is the value stored of first type.
   */
  inline bool isFirst() {
    return type == FIRST;
  }

  /**
   * @brief Is the value stored of second type.
   */
  inline bool isSecond() {
    return type == SECOND;
  }

  /**
   * @brief Gets the value if it is of first type.
   * 
   * Note, if the value is of second type, throws BadEitherAccess.
   * 
   * @return The value stored.
   */
  First getFirst() {
    if (!isFirst()) {
      throw BadEitherAccess();
    }
    return data.first;
  }

  /**
   * @brief Gets the value if it is of second type.
   * 
   * Note, if the value is of first type, throws BadEitherAccess. 
   * 
   * @return The value stored .
   */
  First getSecond() {
    if (!isSecond()) {
      throw BadEitherAccess();
    }
    return data.second;
  }

private:
  /**
   * @brief The type of the either structure.
   */
  enum {
    FIRST,
    SECOND
  } type;

  /**
   * @brief The stored data.
   */
  union {
    First first;
    Second second;
  } data;
};

}  // namespace pioneer