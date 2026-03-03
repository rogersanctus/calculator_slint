#pragma once

#include <functional>
#include <iostream>

class ScoppedConnection {
  std::function<void()> mCleanup;

public:
  ScoppedConnection() = default;
  explicit ScoppedConnection(std::function<void()> cleanup)
      : mCleanup(std::move(cleanup)) {}

  ScoppedConnection(const ScoppedConnection &) = delete;
  ScoppedConnection &operator=(const ScoppedConnection &) = delete;
  // ScoppedConnection(ScoppedConnection &&) noexcept = delete;
  ScoppedConnection &operator=(ScoppedConnection &&) noexcept = delete;

  ScoppedConnection(ScoppedConnection &&other) noexcept
      : mCleanup(std::move(other.mCleanup)) {
    other.mCleanup = nullptr;
  }

  ~ScoppedConnection() {
    if (mCleanup) {
      std::cout << "Cleanup chamado pelo ScoppedConnection" << std::endl;
      mCleanup();
    }
  }
};
