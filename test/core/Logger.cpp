/**
 * @file Logger.cpp
 * @author Riley Horrix (riley@horrix.com)
 * @brief Test file for the Logger class
 * @version 0.1
 * @date 2024-08-24
 * 
 * Copyright (c) Riley Horrix 2024
 */

#include <catch2/catch_test_macros.hpp>

#include "core/Logger.h"

using namespace pioneer;

TEST_CASE("Logger Test", "[logger]") {
  info("[logger] This message should be %s", "normal");
  warn("[logger] This message should be in %s", "yellow");
  error("[logger] This message should be in %s", "red");

  REQUIRE(true);
}