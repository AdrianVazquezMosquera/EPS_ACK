/*
 * Copyright (C) 2018 Theia Space, Universidad Politécnica de Madrid
 *
 * This file is part of Theia Space's ESAT EPS library.
 *
 * Theia Space's ESAT EPS library is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * Theia Space's ESAT EPS library is distributed in the hope that it
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Theia Space's ESAT EPS library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef ESAT_EPSSwitch3V3LineTelecommand_h
#define ESAT_EPSSwitch3V3LineTelecommand_h

#include <Arduino.h>
#include <ESAT_CCSDSTelecommandPacketHandler.h>
#include <ESAT_SemanticVersionNumber.h>

// Telecommand handler for EPS_SWITCH_3V3_LINE.
// Used by ESAT_EPS.
class ESAT_EPSSwitch3V3LineTelecommandClass: public ESAT_CCSDSTelecommandPacketHandler
{
  public:
    // Handle a telecommand packet.
    // The read/write pointer of the packet is at the start of the
    // user data field.
    // Return true on success; otherwise return false.
    boolean handleUserData(ESAT_CCSDSPacket packet);

    // Return the packet identifier of this telecommand handler.
    // ESAT_CCSDSTelecommandPacketDispatcher objects pass telecommand
    // packets to a handler object only when the packet identifiers
    // match.
    byte packetIdentifier()
    {
      return 0x10;
    }

    // Return the version number of this telecommand handler.
    // ESAT_CCSDSTelecommandPacketDispatcher objects pass telecommand
    // packets to a handler object only when the packet version number
    // is backward-compatible with the handler version number.
    ESAT_SemanticVersionNumber versionNumber()
    {
      return ESAT_SemanticVersionNumber(2, 0, 0);
    }
};

// Global instance of ESAT_EPSSwitch3V3LineTelecommandClass.
// Used by ESAT_EPS.
extern ESAT_EPSSwitch3V3LineTelecommandClass ESAT_EPSSwitch3V3LineTelecommand;

#endif /* ESAT_EPS_h */
