
#include <iostream>
#include "libs/dispatcher/notifier.hpp"

int main(int argc, char* argv[])
{
    using ::boilerplate::MqttMessage;
    using ::boilerplate::WssMessage;
    using ::boilerplate::AllMessage;
    using ::boilerplate::notify;

    MqttMessage mqttMessage;
    mqttMessage.setMessage("notification by stefano");
    notify(mqttMessage);

    WssMessage wssMessage;
    wssMessage.setMessage("notification by stefano");
    notify(wssMessage);

    AllMessage allMessage;
    allMessage.setMessage("notification by stefano");
    notify(allMessage);

    return 0;
}