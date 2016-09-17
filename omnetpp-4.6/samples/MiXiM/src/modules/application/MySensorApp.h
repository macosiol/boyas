/***************************************************************************
 * file:        MySensorApp.h
 *
 * author:      Juan Antonio Guerrero
 *
 * copyright:   (C) 2007 CSEM
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 *              For further information see file COPYING
 *              in the top level directory
 ***************************************************************************
 * part of:     framework implementation developed by tkn
 * description: Generate periodic traffic addressed to a sink
 **************************************************************************/

#ifndef SENSOR_APP_H
#define SENSOR_APP_H

#include <map>

#include "MiXiMDefs.h"
#include "BaseModule.h"
#include "BaseLayer.h"
#include "Packet.h"
#include "SimpleAddress.h"
#include "IMobility.h"

class BaseWorldUtility;

/**
 * @brief Test class for the application layer
 *
 * All nodes periodically generate a packet addressed to a sink.
 * This class takes three arguments:
 * - packets: the number of packets to be sent by this application.
 * - trafficType: affects how the time interval between two packets
 * 				is generated. Possible values are "periodic", "uniform",
 * 				and "exponential".
 * - trafficParam: parameter for traffic type. For "periodic" traffic
 * 					this value is the constant time interval, for
 * 					"uniform" traffic this is the maximum time interval
 * 					between two packets and for "exponential" it is
 * 					the mean value. These values are expressed in seconds.
 *
 * @ingroup applLayer
 * @author Amre El-Hoiydi, Jérôme Rousselot
 **/
class MIXIM_API MySensorApp : public BaseLayer
{
    private:
        /** @brief Copy constructor is not allowed.
         */
        MySensorApp(const MySensorApp&);
        /** @brief Assignment operator is not allowed.
         */
        MySensorApp& operator=(const MySensorApp&);

        //Método agregado para imprimir los miembros de un clusterhead
        void printMembers();

    public:
        /** @brief Initialization of the module and some variables*/
        virtual void initialize(int);
        virtual void finish();
        virtual int gettipoNodo();
        virtual void settipoNodo(int);
        virtual ~MySensorApp();

        MySensorApp() :
                BaseLayer(), delayTimer(NULL), myAppAddr(), destAddr(), sentPackets(0), initializationTime(), firstPacketGeneration(), lastPacketReception(), trafficType(
                        0), trafficParam(0.0), nbPackets(0), nbPacketsSent(0), nbPacketsReceived(0), stats(false), trace(
                        false), debug(false), broadcastPackets(false), latencies(), latency(), latenciesRaw(), packet(
                        100), headerLength(0), world(NULL), dataOut(0), dataIn(0), ctrlOut(0), ctrlIn(0)
        {
        } // we must specify a packet length for Packet.h


        enum APPL_MSG_TYPES
        {
            SEND_DATA_TIMER, STOP_SIM_TIMER, DATA_MESSAGE, HELLO_MESSAGE, HELLO_RESPONSE, HELLO_TIMER, NEXT_PAQ, UPDT_REQUEST, UPDT_TIMER, UPDT_RESPONSE, MANTENIMIENTO
        };

        enum TRAFFIC_TYPES
        {
            UNKNOWN = 0, PERIODIC, UNIFORM, EXPONENTIAL, NB_DISTRIBUTIONS,
        };
        enum TIPO_NODO
        {
            DISCONNECTED = 0,  MEMBER_NODE, CLUSTER_HEAD, SINK_NODE,
        };



    protected:
        cMessage * delayTimer;
        cMessage * Espera;   // Mensaje creado para generar temporizador de espera cuando se envió un HELLO
        cMessage * TiempoPaquete;   // Mensaje creado para generar temporizador de espera cuando se envió un HELLO
        cMessage * TiempoActualizacion; //Mensaje temporizador creado para revisar el status de mi nodo padre
        cMessage * TiempoActualizacionResp; //Mensaje temporizador creado para recibir respuesta de mi nodo padre
        LAddress::L3Type myAppAddr;
        LAddress::L3Type destAddr;
        LAddress::L3Type MyFather;
        int sentPackets;
        simtime_t initializationTime;   // Tiempo de espera para enviar el primer paquete
        simtime_t esperaInicializacion;   // Tiempo de espera definido cuando se envía un mensaje HELLO
        simtime_t esperaActualizacion;   // Tiempo de espera definido cuando se envía un mensaje HELLO
        simtime_t esperaActualizacionResp;   // Tiempo de espera definido cuando se envía un mensaje HELLO
        simtime_t firstPacketGeneration;
        simtime_t lastPacketReception;
        // parameters:
        int trafficType;
        double trafficParam;
        int NumPaquete;
        int nbPackets;
        long nbPacketsSent;
        long nbPacketsReceived;
        bool stats;
        bool trace;
        bool banderaInicializacion;
        bool banderaPadre;
        bool debug;
        bool broadcastPackets;
        int TipoNodo;   // Variable para almacenar el tipo de nodo 0=DISCONNECTED, 1=SINK, 2=MEMBER y 3=CLUSTER
        bool Listo;  //Variable utilizada para indicar que el nodo está listo para transmitir paquetes de datos
        int nodoPapi;
        bool configuracion;

        // Código ITSON START ----------------------------------------------
        // Estructura para la tabla de los CH
           int numMiembros;

           struct Nodo {
               int     id;
               double  latitud;
               double  longitud;

               Nodo *pNext;
           };

           //En este arreglo de estructuras se guardan los datos de los nodos miembro (cuando se es CH).
           Nodo *miembro;
        // Código ITSON END ------------------------------------------------


        std::map<LAddress::L3Type, cStdDev> latencies;
        cStdDev latency;
        cOutVector latenciesRaw;
        Packet packet; // informs the simulation of the number of packets sent and received by this node.
        int headerLength;
        BaseWorldUtility* world;

    protected:
        // gates
        int dataOut;
        int dataIn;
        int ctrlOut;
        int ctrlIn;

        /** @brief Handle self messages such as timer... */
        virtual void handleSelfMsg(cMessage *);

        /** @brief Handle messages from lower layer */
        virtual void handleLowerMsg(cMessage *);

        virtual void handleLowerControl(cMessage * msg);

        virtual void handleUpperMsg(cMessage * m)
        {
            delete m;
        }

        virtual void handleUpperControl(cMessage * m)
        {
            delete m;
        }

        /** @brief send a data packet to the next hop */
 /*       virtual void sendData();*/
        virtual void sendHello();  // Función para enviar paquetes HELLO
        virtual void sendData();  // Función para enviar paquetes de DATOS
        virtual void sendUpdate();  // Función para enviar paquete que verifica mi  NODO PADRE
        virtual void scheduleNextPacket();


        /** @brief send a data packet to the next hop */
  /**      virtual void sendHello(); **/
        /** @brief Recognize distribution name. Redefine this method to add your own distribution. */
        virtual void initializeDistribution(const char*);


        /** @brief calculate time to wait before sending next packet, if required. You can redefine this method in a subclass to add your own distribution. */
 /*       virtual void scheduleNextPacket();*/

        /**
         * @brief Returns the latency statistics variable for the passed host address.
         * @param hostAddress the address of the host to return the statistics for.
         * @return A reference to the hosts latency statistics.
         */
        cStdDev& hostsLatency(const LAddress::L3Type& hostAddress);
};

#endif
