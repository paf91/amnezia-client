/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <iostream>

#include "client/platforms/windows/daemon/windowsfirewall_sublayer_result_utils.h"

int main() {
  if (isSublayerLookupError(ERROR_SUCCESS)) {
    std::cerr << "Expected lookup success for ERROR_SUCCESS\n";
    return 1;
  }

  if (isSublayerLookupError(FWP_E_SUBLAYER_NOT_FOUND)) {
    std::cerr << "Expected lookup success for FWP_E_SUBLAYER_NOT_FOUND\n";
    return 2;
  }

  if (!isSublayerLookupError(ERROR_ACCESS_DENIED)) {
    std::cerr << "Expected lookup error for ERROR_ACCESS_DENIED\n";
    return 3;
  }

  if (isSublayerAddError(ERROR_SUCCESS)) {
    std::cerr << "Expected add success for ERROR_SUCCESS\n";
    return 4;
  }

  if (isSublayerAddError(FWP_E_ALREADY_EXISTS)) {
    std::cerr << "Expected add success for FWP_E_ALREADY_EXISTS\n";
    return 5;
  }

  if (!isSublayerAddError(ERROR_ACCESS_DENIED)) {
    std::cerr << "Expected add error for ERROR_ACCESS_DENIED\n";
    return 6;
  }

  if (!isSublayerAlreadyExists(FWP_E_ALREADY_EXISTS)) {
    std::cerr << "Expected already-exists detection for FWP_E_ALREADY_EXISTS\n";
    return 7;
  }

  if (isSublayerAlreadyExists(ERROR_SUCCESS)) {
    std::cerr << "Expected non-exists result for ERROR_SUCCESS\n";
    return 8;
  }

  return 0;
}
