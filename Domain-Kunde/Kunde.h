//
// Created by Vanessa on 02.05.2024.
//

#ifndef CARSHARING_712_1_KUNDE_H
#define CARSHARING_712_1_KUNDE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
class Kunde {
private:
    string id_;
    string name_;
    string vorname_;
    string email_;
    string handy_;
    string adresse_;
    string bemerkungen_;
    bool gdprDeleted_;

public:
    Kunde(string id, string name, string vorname, string email, string handy, string adresse,
          string bemerkungen, bool gdprDeleted);

    string getId() const;
    string getName() const;
    string getVorname() const;
    string getEmail() const;
    string getHandy() const;
    string getAdresse() const;
    string getBemerkungen() const;
    bool getGdprDeleted() const;
    bool hatAutoBestellt() const;
    void setName(const string& name);
    void setVorname(const string& vorname);
    void setEmail(const string& email);
    void setHandy(const string& handy);
    void setAdresse(const string& adresse);
    void setBemerkungen(const string& bemerkungen);
    void setGdprDeleted(bool gdprDeleted);

private:
    void setId(const string& id);
};




#endif //CARSHARING_712_1_KUNDE_H
