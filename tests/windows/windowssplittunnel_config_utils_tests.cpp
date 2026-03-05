/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <iostream>

#include "client/platforms/windows/daemon/windowssplittunnel_config_utils.h"

int main() {
  if (isAppSplitTunnelRequested(kAppRouteAllApps, 1)) {
    std::cerr << "Expected all-apps mode to disable app split tunneling\n";
    return 1;
  }

  if (isAppSplitTunnelRequested(kAppRouteOnlyForward, 0)) {
    std::cerr << "Expected empty include list to disable app split tunneling\n";
    return 2;
  }

  if (!isAppSplitTunnelRequested(kAppRouteOnlyForward, 1)) {
    std::cerr << "Expected include mode with apps to request split tunneling\n";
    return 3;
  }

  if (!isAppSplitTunnelRequested(kAppRouteAllExcept, 2)) {
    std::cerr << "Expected exclude mode with apps to request split tunneling\n";
    return 4;
  }

  if (appSplitTunnelDriverMode(kAppRouteOnlyForward) != kDriverModeInclude) {
    std::cerr << "Expected include driver mode for only-forward route type\n";
    return 5;
  }

  if (appSplitTunnelDriverMode(kAppRouteAllExcept) != kDriverModeExclude) {
    std::cerr << "Expected exclude driver mode for all-except route type\n";
    return 6;
  }

  return 0;
}
