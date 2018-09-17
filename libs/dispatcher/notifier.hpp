

#ifndef UTIL_NOTIFICATE_HPP
#define UTIL_NOTIFICATE_HPP

#include <iostream>
#include <string>
#include <iterator>
#include "include/message_traits.hpp"

namespace boilerplate
{
    struct mqtt_message_tag
    {
    };

    struct wss_message_tag
    {
    };

    struct http_message_tag
    {
    };

    struct tcp_message_tag
    {
    };

    struct udp_message_tag
    {
    };

    struct all_message_tag
    {
    };

    struct GeneralMessage
    {
        std::string message;
    public:
        const std::string &getMessage() const
        {
            return message;
        }

        void setMessage(const std::string &message)
        {
            GeneralMessage::message = message;
        }

        virtual ~GeneralMessage() = 0;
    };

    inline GeneralMessage::~GeneralMessage()
    {
    }

    struct MqttMessage final : public GeneralMessage
    {
        typedef mqtt_message_tag message_category;
    };

    struct WssMessage final : public GeneralMessage
    {
        typedef wss_message_tag message_category;
    };

    struct AllMessage final : public GeneralMessage
    {
        typedef all_message_tag message_category;
    };

    namespace details
    {
        inline void notify_dispatch(std::string const &notification, boilerplate::mqtt_message_tag)
        {
            std::cerr << "MQTT: " << notification << std::endl;
            // code to publish to topic
        }

        inline void notify_dispatch(std::string const &notification, boilerplate::wss_message_tag)
        {
            std::cerr << "WSS: " << notification << std::endl;
            // code to broadcast to connected clients            
        }

        inline void notify_dispatch(std::string const &notification, boilerplate::all_message_tag)
        {
            std::cerr << "ALL: " << notification << std::endl;
            notify_dispatch(notification, boilerplate::mqtt_message_tag());
            notify_dispatch(notification, boilerplate::wss_message_tag());
        }
    }

    template<class __Message>
    void notify(__Message const &message)
    {
        typedef typename message_traits<__Message>::message_category category;
        details::notify_dispatch(message.getMessage(), category());
    }
}

#endif //UTIL_NOTIFICATE_HPP