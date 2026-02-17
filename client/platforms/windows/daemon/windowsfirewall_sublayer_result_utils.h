/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef WINDOWSFIREWALL_SUBLAYER_RESULT_UTILS_H
#define WINDOWSFIREWALL_SUBLAYER_RESULT_UTILS_H

// Keep this self-contained for unit tests that include it directly.
// windows.h must be included before fwpmu.h.
#include <windows.h>
#include <fwpmu.h>

inline bool isSublayerLookupError(DWORD result) {
  return result != ERROR_SUCCESS && result != FWP_E_SUBLAYER_NOT_FOUND;
}

inline bool isSublayerAddError(DWORD result) {
  return result != ERROR_SUCCESS && result != FWP_E_ALREADY_EXISTS;
}

inline bool isSublayerAlreadyExists(DWORD result) {
  return result == FWP_E_ALREADY_EXISTS;
}

#endif  // WINDOWSFIREWALL_SUBLAYER_RESULT_UTILS_H
