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
  ESAT_CCSDSSecondaryHeader datum = packet.readSecondaryHeader();
  return datum;
}

boolean ESAT_EPSACKEPSSubsystemClass::handlerIsCompatibleWithPacket(ESAT_CCSDSTelecommandPacketHandler &handler,
                                                                    ESAT_CCSDSSecondaryHeader secondaryHeader)
{
  if (handler.packetIdentifier() == secondaryHeader.packetIdentifier)
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
  // We read some error flags and we must reset them after use.
  packet.writeBoolean(handlerIsCompatibleWithPacket(ESAT_EPSDisableTelemetryTelecommand, datum));
  packet.writeBoolean(handlerIsCompatibleWithPacket(ESAT_EPSEnableTelemetryTelecommand, datum));
  packet.writeBoolean(handlerIsCompatibleWithPacket(ESAT_EPSFixedModeTelecommand, datum));
  packet.writeBoolean(handlerIsCompatibleWithPacket(ESAT_EPSMaximumPowerPointTrackingModeTelecommand, datum));
  packet.writeBoolean(handlerIsCompatibleWithPacket(ESAT_EPSSetTimeTelecommand, datum));
  packet.writeBoolean(handlerIsCompatibleWithPacket(ESAT_EPSSweepModeTelecommand, datum));
  packet.writeBoolean(handlerIsCompatibleWithPacket(ESAT_EPSSwitch3V3LineTelecommand, datum));
  packet.writeBoolean(handlerIsCompatibleWithPacket(ESAT_EPSSwitch5VLineTelecommand, datum));
  return true;
}

ESAT_EPSACKEPSSubsystemClass ESAT_EPSACKEPSSubsystem;
