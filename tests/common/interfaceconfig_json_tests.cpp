/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <iostream>

#include <QJsonArray>
#include <QJsonObject>

#include "client/daemon/interfaceconfig.h"

int main() {
  InterfaceConfig config;
  config.m_hopType = InterfaceConfig::SingleHop;
  config.m_vpnDisabledApps = {"C:/Program Files/App/app.exe"};
  config.m_appSplitTunnelType = 2;

  const QJsonObject json = config.toJson();
  const QJsonArray apps = json.value("vpnDisabledApps").toArray();

  if (apps.size() != 1 || apps.at(0).toString() != "C:/Program Files/App/app.exe") {
    std::cerr << "Expected vpnDisabledApps to be serialized\n";
    return 1;
  }

  if (json.value("appSplitTunnelType").toInt(-1) != 2) {
    std::cerr << "Expected appSplitTunnelType to be serialized\n";
    return 2;
  }

  return 0;
}
