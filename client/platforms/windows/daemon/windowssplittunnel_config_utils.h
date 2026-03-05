/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef WINDOWSSPLITTUNNEL_CONFIG_UTILS_H
#define WINDOWSSPLITTUNNEL_CONFIG_UTILS_H

#include <cstdint>

constexpr int kAppRouteAllApps = 0;
constexpr int kAppRouteOnlyForward = 1;
constexpr int kAppRouteAllExcept = 2;

constexpr uint32_t kDriverModeExclude = 0;
constexpr uint32_t kDriverModeInclude = 1;

inline bool isAppSplitTunnelRequested(int appSplitTunnelType, int appCount) {
  return appCount > 0 &&
         (appSplitTunnelType == kAppRouteOnlyForward ||
          appSplitTunnelType == kAppRouteAllExcept);
}

inline uint32_t appSplitTunnelDriverMode(int appSplitTunnelType) {
  return appSplitTunnelType == kAppRouteOnlyForward ? kDriverModeInclude
                                                    : kDriverModeExclude;
}

#endif  // WINDOWSSPLITTUNNEL_CONFIG_UTILS_H
