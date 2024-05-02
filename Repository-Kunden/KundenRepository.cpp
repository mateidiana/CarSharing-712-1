//
// Created by Vanessa on 02.05.2024.
//

#include "KundenRepository.h"

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
