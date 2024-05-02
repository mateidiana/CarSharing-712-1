//
// Created by Vanessa on 02.05.2024.
//

#include "Kunde.h"

Kunde::Kunde(string id, string name, string vorname, string email, string handy,
             string adresse, string bemerkungen, bool gdprDeleted): id_(id), name_(name), vorname_(vorname), email_(email),
                                                                    handy_(handy), adresse_(adresse), bemerkungen_(bemerkungen), gdprDeleted_(gdprDeleted) {}

string Kunde::getId() const {
    return id_;
}

string Kunde::getName() const {
    return name_;
}

string Kunde::getVorname() const {
    return vorname_;
}

string Kunde::getEmail() const {
    return email_;
}

string Kunde::getHandy() const {
    return handy_;
}

string Kunde::getAdresse() const {
    return adresse_;
}

string Kunde::getBemerkungen() const {
    return bemerkungen_;
}

bool Kunde::getGdprDeleted() const {
    return gdprDeleted_;
}

bool Kunde::hatAutoBestellt() const {
    //aici trebuie sa faca si ceilalti codul sa pot implementa
    return false;
}

void Kunde::setName(const string& name) {
    name_ = name;
}

void Kunde::setVorname(const string& vorname) {
    vorname_ = vorname;
}

void Kunde::setEmail(const string& email) {
    email_ = email;
}

void Kunde::setHandy(const string& handy) {
    handy_ = handy;
}

void Kunde::setAdresse(const string& adresse) {
    adresse_ = adresse;
}

void Kunde::setBemerkungen(const string& bemerkungen) {
    bemerkungen_ = bemerkungen;
}

void Kunde::setGdprDeleted(bool gdprDeleted) {
    gdprDeleted_ = gdprDeleted;
}

void Kunde::setId(const string& id) {
    id_ = id;
}
