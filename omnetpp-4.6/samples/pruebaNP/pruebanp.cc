//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "IEEE802154Enum.h"
USING_NAMESPACE

// Include a generated file: the header file created from tictoc13.msg.
// It contains the definition of the TictocMsg10 class, derived from
// cMessage.

class Txc13 : public SimpleModule
{
  protected:
    virtual MPDU_m *generateMessage();
    virtual void forwardMessage(MPDU_m *msg);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(Txc13);
void Txc13::initialize()
{
    // Module 0 sends the first message
    if (getIndex() == 0) {
        // Boot the process scheduling the initial message as a self-message.
        MPDU_m *msg = generateMessage();
        scheduleAt(0.0, msg);
    }
}
void Txc13::handleMessage(cMessage *msg)
{
    MPDU_m *ttmsg = check_and_cast<MPDU_m *>(msg);
    if (ttmsg->getDestination() == getIndex()) {
        // Message arrived.
        EV << "Message " << ttmsg << " arrived after " << ttmsg->getHopCount() << " hops.\n";
        bubble("ARRIVED, starting new one!");
        delete ttmsg;
        // Generate another one.
        EV << "Generating another message: ";
        MPDU_m *newmsg = generateMessage();
        EV << newmsg << endl;
        forwardMessage(newmsg);
    }
    else {
        // We need to forward the message.
        forwardMessage(ttmsg);
    }
}
MPDU_m *Txc13::generateMessage()
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
    MPDU_m *msg = new MPDU_m(msgname);
    msg->setSource(src);
    msg->setDestination(dest);
    return msg;
}
void Txc13::forwardMessage(MPDU_m *msg)
{
    // Increment hop count.
    msg->setHopCount(msg->getHopCount()+1);
    // Same routing as before: random gate.
    int n = gateSize("gate");
    int k = intuniform(0, n-1);
    EV << "Forwarding message " << msg << " on gate[" << k << "]\n";
    send(msg, "gate$o", k);
}
