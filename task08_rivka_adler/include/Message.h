#pragma once
/**
 * @struct Message
 * @brief A struct representing a message with an ID, a value, and a flag indicating if it is the last message.
 *
 * The Message struct represents a message that can be used to communicate information. It contains an ID, a value, and a flag to indicate if it is the last message in a series. The struct provides default values for each member.
 */
struct Message
{
    double id=0.0;
    double value=9;
    bool isLast=false;
};
