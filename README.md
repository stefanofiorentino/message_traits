## Message Traits
### Message dispatching using type traits.
In order to understand a cumbersome topic, you have to work yourself on transforming an idea into reality.
This repository is all about this: implementing a simple type_traits mechanism to better grasp the concept itself.

## Target 
The target of this technique, up to me, is just to hide the greater part of the boilerplate code to the library users,
freeing the application developers from expliciting the tags in the function caller code.

## Target usage
The target code I want to have in my application code is the following:

```cpp
    MqttMessage mqttMessage;
    mqttMessage.setMessage("notification by stefano over mqtt");
    notify(mqttMessage);

    WssMessage wssMessage;
    wssMessage.setMessage("notification by stefano over wss");
    notify(wssMessage);
    
    AllMessage allMessage;
    allMessage.setMessage("notification by stefano over all available channels");
    notify(allMessage);
```

The `notify` function could/should be implemented in a hugely easier way but, for this example, I will implement it leveraging the type_traits concept.
The instance, one of the several kinds of message the application can feed to the `notify` function, brings internally the information about the kind.
Doing so the application developer (aka the library user) can call the function without any angle brackets.
  
## Data type declaration
The data type hides inside itself the message category
```cpp
    struct MqttMessage final : public GeneralMessage
    {
        typedef mqtt_message_tag message_category;
    };
```
where `mqtt_message_tag` is just a struct tag declared as
```cpp
    struct mqtt_message_tag{};
```

## Notify function
The `notify` function is defined as follows:
```cpp
    template<class __Message>
    void notify(__Message const &message)
    {
        typedef typename message_traits<__Message>::message_category category;
        details::notify_dispatch(message.getMessage(), category());
    }
```
where:
- `notify` is a template function accepting a generic message
- inside the function the category type is defined thanks to the message_traits utility struct
- the namespaced, and hence potentially hidden, function `notify_dispatch` leverages the tag dispatching to select the right function to call between the various implementations

## The type-trait
The template struct 
```cpp
    template<typename __Message>
    struct message_traits
    {
        typedef typename __Message::message_category message_category;
    };
```
is the piece of code that does the trick. It is a generic struct that acts as category pusher, which is in charge of exposing the message_category of the template generic parameter.
 
## Extra
### Building
Along with the repo you have a very basic Dockerfile to automatically build and just see what happens 
    
    docker build -t message_traits .

### CLion
Being this repo a CMake project, you can just open it with CLion and run it in debug.