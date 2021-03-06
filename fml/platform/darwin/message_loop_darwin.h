// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_FML_PLATFORM_DARWIN_MESSAGE_LOOP_DARWIN_H_
#define FLUTTER_FML_PLATFORM_DARWIN_MESSAGE_LOOP_DARWIN_H_

#include <CoreFoundation/CoreFoundation.h>

#include <atomic>

#include "flutter/fml/message_loop_impl.h"
#include "flutter/fml/platform/darwin/cf_utils.h"
#include "lib/fxl/macros.h"

namespace fml {

class MessageLoopDarwin : public MessageLoopImpl {
 private:
  std::atomic_bool running_;
  CFRef<CFRunLoopTimerRef> delayed_wake_timer_;
  CFRef<CFRunLoopRef> loop_;

  MessageLoopDarwin();

  ~MessageLoopDarwin() override;

  void Run() override;

  void Terminate() override;

  void WakeUp(fxl::TimePoint time_point) override;

  static void OnTimerFire(CFRunLoopTimerRef timer, MessageLoopDarwin* loop);

  FRIEND_MAKE_REF_COUNTED(MessageLoopDarwin);
  FRIEND_REF_COUNTED_THREAD_SAFE(MessageLoopDarwin);
  FXL_DISALLOW_COPY_AND_ASSIGN(MessageLoopDarwin);
};

}  // namespace fml

#endif  // FLUTTER_FML_PLATFORM_DARWIN_MESSAGE_LOOP_DARWIN_H_
