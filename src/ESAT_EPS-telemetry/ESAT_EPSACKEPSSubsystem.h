/*
 * Copyright (C) 2018, 2019 Theia Space, Universidad Politécnica de Madrid
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

#ifndef ESAT_EPSACKEPSSubsystem_h
#define ESAT_EPSACKEPSSubsystem_h

#include <Arduino.h>
#include <ESAT_CCSDSTelemetryPacketContents.h>
#include <ESAT_CCSDSSecondaryHeader.h>
#include <ESAT_CCSDSTelecommandPacketHandler.h>


// EPS housekeeping telemetry packet contents.
// Use the global instance ESAT_EPSACKEPSSubsystem.
class ESAT_EPSACKEPSSubsystemClass: public ESAT_CCSDSTelemetryPacketContents
{
  public:
    // Return true when a new telemetry packet is available;
    // otherwise return false.
    boolean available();
    boolean makeAvaliable(bool isAvaliable);
    bool activated;

    // Return the packet identifier of EPS housekeeping telemetry.
    byte packetIdentifier()
    {
      return 0x02;
    }

    // Fill the user data section of the provided packet
    // with EPS housekeeping telemetry.
    // Return true on success; otherwise return false.
    boolean fillUserData(ESAT_CCSDSPacket& packet);


    boolean handlerIsCompatibleWithPacket(ESAT_CCSDSTelecommandPacketHandler& handler,
                                          ESAT_CCSDSSecondaryHeader secondaryHeader);


    ESAT_CCSDSSecondaryHeader saveSecondaryHeader(ESAT_CCSDSPacket& packet);
    ESAT_CCSDSSecondaryHeader datum;

};

// Global instance of the ESAT_EPSACKEPSSubsystem library.
extern ESAT_EPSACKEPSSubsystemClass ESAT_EPSACKEPSSubsystem;

#endif /* ESAT_EPSACKEPSSubsystem */
