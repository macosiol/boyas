//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#pragma once

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "mcpsData_m.h"

USING_NAMESPACE

// Include a generated file: the header file created from tictoc13.msg.
// It contains the definition of the TictocMsg10 class, derived from
// cMessage.

class Txc13 : public cSimpleModule
{
  protected:
    virtual mcpsDataReq *generateMessage();
    virtual void forwardMessage(mcpsDataReq *msg);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(Txc13);
void Txc13::initialize()
{
    // Module 0 sends the first message
    if (getIndex() == 0) {
        // Boot the process scheduling the initial message as a self-message.
        mcpsDataReq *msg = generateMessage();
        scheduleAt(0.0, msg);
    }
}
void Txc13::handleMessage(cMessage *msg)
{
    mcpsDataReq *ttmsg = check_and_cast<mcpsDataReq *>(msg);
    if (ttmsg->getKeySource() == getIndex()) {
        // Message arrived.
        EV << "Message " << ttmsg << " arrived after " << ttmsg->getDstAddr() << " hops.\n";
        bubble("ARRIVED, starting new one!");
        delete ttmsg;
        // Generate another one.
        EV << "Generating another message: ";
        mcpsDataReq *newmsg = generateMessage();
        EV << newmsg << endl;
        forwardMessage(newmsg);
    }
    else {
        // We need to forward the message.
        forwardMessage(ttmsg);
    }
}
mcpsDataReq *Txc13::generateMessage()
{
    // Produce source and destination addresses.
    int src = getIndex();  // our module index
    int n = getVectorSize();  // module vector size
    int dest = intuniform(0, n-2);
    if (dest >= src)
        dest++;
    char msgname[20];
    sprintf(msgname, "tic-%d-to-%d", src, dest);
    // Create message object and set source and destination field.
    mcpsDataReq *msg = new mcpsDataReq(msgname);
    src=msg->getKeySource();
    msg->setKeySource(dest);
    return msg;
}
void Txc13::forwardMessage(mcpsDataReq *msg)
{
    // Increment hop count.
    //msg->setHopCount(msg->getHopCount()+1);
    // Same routing as before: random gate.
    int n = gateSize("gate");
    int k = intuniform(0, n-1);
    EV << "Forwarding message " << msg << " on gate[" << k << "]\n";
    send(msg, "gate$o", k);
}
