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

#include "ESAT_EPS-telemetry/ESAT_EPSACKEPSSubsystem.h"
#include <ESAT_CCSDSTelecommandPacketDispatcher.h>
#include "ESAT_EPS-telecommands/ESAT_EPSSwitch3V3LineTelecommand.h"
#include "ESAT_EPS-telecommands/ESAT_EPSFixedModeTelecommand.h"
#include "ESAT_EPS-telecommands/ESAT_EPSSwitch5VLineTelecommand.h"
#include "ESAT_EPS-telecommands/ESAT_EPSSweepModeTelecommand.h"
#include "ESAT_EPS-telecommands/ESAT_EPSSetTimeTelecommand.h"
#include "ESAT_EPS-telecommands/ESAT_EPSMaximumPowerPointTrackingModeTelecommand.h"
#include "ESAT_EPS-telecommands/ESAT_EPSDisableTelemetryTelecommand.h"
#include "ESAT_EPS-telecommands/ESAT_EPSEnableTelemetryTelecommand.h"
#include "ESAT_EPS-telecommands/ESAT_EPSFixedModeTelecommand.h"

boolean ESAT_EPSACKEPSSubsystemClass::makeAvaliable(bool isAvaliable)
{
  return activated = isAvaliable;
}

boolean ESAT_EPSACKEPSSubsystemClass::available()
{
  if (activated == true)
  {
    return true;
  }
  else
  {
    return false;
  }
}

ESAT_CCSDSSecondaryHeader ESAT_EPSACKEPSSubsystemClass::saveSecondaryHeader(ESAT_CCSDSPacket &packet)
{
  return datum = packet.readSecondaryHeader();
}

boolean ESAT_EPSACKEPSSubsystemClass::handlerIsCompatibleWithPacket(byte packetIdentifier,
                                                                    ESAT_CCSDSSecondaryHeader datum)
{
  if (packetIdentifier == datum.packetIdentifier)
  {
    return true;
  }
  else
  {
    return false;
  }
}

boolean ESAT_EPSACKEPSSubsystemClass::fillUserData(ESAT_CCSDSPacket &packet)
{

  byte handlers[] = {ESAT_EPSDisableTelemetryTelecommand.packetIdentifier(),
                     ESAT_EPSEnableTelemetryTelecommand.packetIdentifier(),
                     ESAT_EPSFixedModeTelecommand.packetIdentifier(),
                     ESAT_EPSMaximumPowerPointTrackingModeTelecommand.packetIdentifier(),
                     ESAT_EPSSetTimeTelecommand.packetIdentifier(),
                     ESAT_EPSSweepModeTelecommand.packetIdentifier(),
                     ESAT_EPSSwitch3V3LineTelecommand.packetIdentifier(),
                     ESAT_EPSSwitch5VLineTelecommand.packetIdentifier()};

  for (int i = 0; i < 8; i++)
  {
    if (handlerIsCompatibleWithPacket(handlers[i], datum))
    {
      packet.writeByte(handlers[i]);
    }
  }

  return true;
}

ESAT_EPSACKEPSSubsystemClass ESAT_EPSACKEPSSubsystem;
