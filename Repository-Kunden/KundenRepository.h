//
// Created by Vanessa on 02.05.2024.
//

#ifndef CARSHARING_712_1_KUNDENREPOSITORY_H
#define CARSHARING_712_1_KUNDENREPOSITORY_H

#include <vector>
#include <stdexcept>
#include "../Domain-Kunde/Kunde.h"

using namespace std;
class KundenRepository {

private:
    vector<Kunde> kunden_;

public:
    void erstelleKunde(const Kunde& kunde, bool istMitarbeiter);
    void aendereKunde(const Kunde& kunde, bool istMitarbeiter);
    void loscheKunde(const Kunde& kunde, bool istMitarbeiter);
    void anonymisiereKunde(const Kunde& kunde, bool istMitarbeiter);
};



#endif //CARSHARING_712_1_KUNDENREPOSITORY_H
