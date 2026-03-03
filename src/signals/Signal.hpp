#pragma once

#include "signals/ScoppedConnection.hpp"
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <map>

template <typename... Args> class Signal {
  using Slot = std::function<void(Args...)>;
  std::map<size_t, Slot> mSlots;
  size_t mNextId;

public:
  ScoppedConnection connect(Slot slot) {
    size_t id = mNextId++;

    mSlots[id] = std::move(slot);

    return ScoppedConnection([this, id]() {
      mSlots.erase(id);
      std::cout << "Slot removido pelo Signal" << std::endl;
    });
  }

  void emit(Args... args) const {
    for (const auto &[id, slot] : mSlots) {
      slot(args...);
    }
  }
};
