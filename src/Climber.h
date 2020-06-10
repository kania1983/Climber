﻿//
// Created by Climber on 2020/6/9.
//

#ifndef CLIMBER_CLIMBER_H
#define CLIMBER_CLIMBER_H

#include <wx/process.h>
#include "ServerConfItem.h"

#define CLIMBER (Climber::GetInstance())

class Climber {
public:
    static void Init();

    static void Destroy();

    static Climber &GetInstance();

private:
    Climber();

    static Climber *s_instance;

public:
    bool IsRunning() const;

    void Start();

    void Stop();

    void Restart();

    void SetSystemProxy();

    void ClearSystemProxy();

private:
    static void RunShadowsocks(const ServerConfItem *conf);

    static void RunTrojan(const ServerConfItem *conf);

    static void KillClient();

    static void RunPrivoxy();

    static void KillPrivoxy();

private:
    bool m_running = false;

};


#endif //CLIMBER_CLIMBER_H
