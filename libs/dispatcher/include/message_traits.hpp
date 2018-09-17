#ifndef MESSAGE_TRAITS_HPP
#define MESSAGE_TRAITS_HPP

namespace boilerplate
{
    template<typename __Message>
    struct message_traits
    {
        typedef typename __Message::message_category message_category;
    };
}

#endif //MESSAGE_TRAITS_HPP