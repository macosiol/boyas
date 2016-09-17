//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

cplusplus {{
    #include "SimpleAddress.h"
}}

class LAddress::L3Type extends void;

// Basic application packet definition
//
// subclass if you want to create your own application layer packet
// class
//
// @author Daniel Willkomm - MACL-UABC
packet HelloPkt
{
    LAddress::L3Type destAddr = LAddress::L3BROADCAST; // destination address
    LAddress::L3Type srcAddr  = LAddress::L3BROADCAST; // source address
    float X_CoorGeo;
    float Y_CoorGeo;
    float Z_CoorGeo;
    int Tipo_Nodo;
    int NodoID;
}
