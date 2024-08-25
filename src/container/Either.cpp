/**
 * @file Either.cpp
 * @author Riley Horrix (riley@horrix.com)
 * @brief Implementation of Either class
 * @version 0.1
 * @date 2024-08-24
 * 
 * Copyright (c) Riley Horrix 2024
 */

#include "container/Either.h"

#include <string>

using namespace pioneer;

BadEitherAccess::BadEitherAccess():
  LogicError("[BadEitherAccess] :: Tried to access the wrong type in an "
  "Either object. Check the type before accessing the object.") {
}