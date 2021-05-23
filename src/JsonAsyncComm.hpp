/**
 * @file JsonAsyncComm.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "ArduinoJson.h"

class JsonAsyncComm
{
private:
    DynamicJsonDocument dataBase;
    void (*sendData)(String data);
    StaticJsonDocument<96> frame;
public:
    JsonAsyncComm():dataBase(512) {}
    JsonAsyncComm(int dataBaseSize):dataBase(dataBaseSize) {}
    ~JsonAsyncComm() {}

    void setSendDataCallback(void (*sendData)(String data)){
        this->sendData = sendData;
    }

    void updateDataBase(String jsonMsgStr){
        StaticJsonDocument<96> frame;
        deserializeJson(frame, jsonMsgStr);

        String key = frame["N"];
        dataBase[key] = frame["V"];
    }

    void getVariable(int variable);
    void getVariable(float variable);
    void getVariable(char variable);
    void getVariable(String variable);
    void setVariable(int variable, int value);
    void setVariable(float variable, float value);
    void setVariable(char variable, char value);
    void setVariable(String variable, String value);

    void updateValueByKey(String key, int *value){
        if(dataBase.containsKey(key)) *value = dataBase[key];
    }

    void updateValueByKey(String key, float *value){
        if(dataBase.containsKey(key)) *value = dataBase[key];
    }

    void updateValueByKey(String key, char *value){
        if(dataBase.containsKey(key)) *value = dataBase[key];
    }

    void updateValueByKey(String key, String *value){
        if(dataBase.containsKey(key)) *value = dataBase[key].as<String>();
    }

    void updateValueByKey(String key, int value){
        if(dataBase[key] != value){
            String jsonMsg;
            dataBase[key] = value;
            frame["N"] = key;
            frame["V"] = value;
            jsonMsg += '\n';
            serializeJson(frame, jsonMsg);
            sendData(jsonMsg);
        }
    }

    void updateValueByKey(String key, float value){
        if(dataBase[key] != value){
            String jsonMsg;
            dataBase[key] = value;
            frame["N"] = key;
            frame["V"] = value;
            jsonMsg += '\n';
            serializeJson(frame, jsonMsg);
            sendData(jsonMsg);
        }
    }

    void updateValueByKey(String key, char value){
        if(dataBase[key] != value){
            String jsonMsg;
            dataBase[key] = value;
            frame["N"] = key;
            frame["V"] = value;
            jsonMsg += '\n';
            serializeJson(frame, jsonMsg);
            sendData(jsonMsg);
        }
    }

    void updateValueByKey(String key, String value){
        if(dataBase[key] != value){
            String jsonMsg;
            dataBase[key].as<String>() = value;
            frame["N"] = key;
            frame["V"] = value;
            jsonMsg += '\n';
            serializeJson(frame, jsonMsg);
            sendData(jsonMsg);
        }
    }

    DynamicJsonDocument getJsonDoc(){
        return dataBase;
    }

    String getDataBase(){
        String dataBaseStr;
        serializeJson(dataBase, dataBaseStr);
        return dataBaseStr;
    }
};