//
// Created by Vanessa on 02.05.2024.
//

#include "KundenRepository.h"

KundenRepository::KundenRepository() {
    startData();
}

void KundenRepository::erstelleKunde(const Kunde& kunde, bool istMitarbeiter) {
    if (!istMitarbeiter) {
        throw invalid_argument("Nur Mitarbeiter dürfen Kunden erstellen.");
    }
    kunden_.push_back(kunde);
}

void KundenRepository::aendereKunde(const Kunde& kunde, bool istMitarbeiter) {
    if (!istMitarbeiter) {
        throw invalid_argument("Nur Mitarbeiter dürfen Kunden ändern.");
    }
    for (int i = 0; i < kunden_.size(); ++i) {
        if (kunden_[i].getName() == kunde.getName()) {
            kunden_[i] = kunde;
            return;
        }
    }
    throw invalid_argument("Kunde nicht gefunden");
}

void KundenRepository::loscheKunde(const Kunde& kunde, bool istMitarbeiter) {
    if (!istMitarbeiter) {
        throw invalid_argument("Nur Mitarbeiter dürfen Kunden löschen.");
    }
    for (int i = 0; i < kunden_.size(); ++i) {
        if (kunden_[i].getName() == kunde.getName()) {
            kunden_.erase(kunden_.begin() + i);
            return;
        }
    }
    throw invalid_argument("Kunde nicht gefunden");
}

void KundenRepository::anonymisiereKunde(const Kunde& kunde, bool istMitarbeiter) {
    if (!istMitarbeiter) {
        throw invalid_argument("Nur Mitarbeiter dürfen Kunden anonymisieren.");
    }
    for (int i = 0; i < kunden_.size(); ++i) {
        if (kunden_[i].getId() == kunde.getId()) {
            kunden_[i].setName("Kunde-" + kunden_[i].getId());
            kunden_[i].setVorname("Unbekannt");
            kunden_[i].setEmail("");
            kunden_[i].setHandy("");
            kunden_[i].setAdresse("");
            kunden_[i].setBemerkungen("");
            kunden_[i].setGdprDeleted(true);
            return;
        }
    }
    throw invalid_argument("Kunde nicht gefunden");
}

vector<Kunde> KundenRepository::getAll() { return kunden_; }

void KundenRepository::startData() {
    kunden_.push_back(Kunde("1","Popescu","Bob","bob1@yahoo.com","1234567892","Plopilor 1","", false));
    kunden_.push_back(Kunde("2","Georgescu","Zob","zob@yahoo.com","2341567345","Moldoveanu 15","", false));
    kunden_.push_back(Kunde("3","Florescu","Dob","dob25@yahoo.com","5678345123","Ariesului 112","", false));
    kunden_.push_back(Kunde("4","Grigorescu","Cob","ciob15@yahoo.com","4567123234","Bucium 20","", false));
    kunden_.push_back(Kunde("5","Vladescu","Ana","anavld@yahoo.com","2345123897","Cisnadiei 2","", false));
    kunden_.push_back(Kunde("6","Andrei","Maria","andreimaria5@yahoo.com","5678456098","Baciului 4","", false));
    kunden_.push_back(Kunde("7","George","Mihai","mihaig@yahoo.com","4567345234","Negoi 12","", false));
    kunden_.push_back(Kunde("8","Mihaelescu","Laura","lauram@yahoo.com","5678456345","Florilor 15","", false));
    kunden_.push_back(Kunde("9","Neamtu","Andreea","neamtuandreea@yahoo.com","4567234123","Farului 1","", false));
    kunden_.push_back(Kunde("10","Fader","Bianca","biancafad@yahoo.com","6789467125","Gradinii 45","", false));
}
