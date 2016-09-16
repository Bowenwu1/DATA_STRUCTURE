#include "TrainManager.hpp"

std::string TrainManager::getInstruction(std::vector<int> data) {
    std::string result;

    // check whether this data is legal
    std::vector<int> temp = data;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); ++i) {
        if (temp[i] != i + 1)
            return std::string("Your input is illegal! Please try again!");
    }

    // default set
    std::queue<int> train;
    for (int i = 0; i < data.size(); ++i)
        train.push(data[i]);
    
    // storage track data
    std::vector<std::stack<int>> track;
    int hold = 1;
    while (hold != data.size() + 1) {
        // First handle those train in track
        bool whether_operation = false;
        for (int i = 0; i < track.size(); ++i) {
            if (!track.empty())
                if (track[i].top() == hold) {
                    result += TrainManager::
                    InstructionToString(track[i].top(), i + 1, 0);
                    ++hold;
                    track[i].pop();
                    whether_operation = true;
                }
        }
        if (whether_operation)
            continue;


        bool whether_enough = false;

        // move the directly to target
        if (train.front() == hold) {
            result += TrainManager::
            InstructionToString(train.front(), 0, 0);
            train.pop();
            ++hold;
            whether_enough = true;
        } else {
            for (int i = 0; i < track.size(); ++i) {
                if (track[i].empty()) {
                    result += TrainManager::
                    InstructionToString(train.front(), 0, i + 1);
                    whether_enough = true;
                    track[i].push(train.front());
                    train.pop();
                    break;
                } else if (track[i].top() > train.front()) {
                    result += TrainManager::
                    InstructionToString(train.front(), 0, i + 1);
                    whether_enough = true;
                    track[i].push(train.front());
                    train.pop();
                    break;
                }
            }
        }

        // handle there is not enough track
        if (!whether_enough) {
            track.push_back(std::stack<int>());
            result += TrainManager::
            InstructionToString(train.front(), 0, track.size());
            track[track.size() - 1].push(train.front());
            train.pop();
        }
    }
    return TrainManager::InstructionToString(track.size()) + "\n"
        + result;
}

std::string TrainManager::InstructionToString(int trainNum, int from, int to) {
    std::stringstream ss;
    if (!from && !to) {
        ss << "Directly Move Train No." << trainNum 
        << " to target." << std::endl;
        return ss.str();
    }
    if (!from) {
        ss << "Move Train No." << trainNum << " from origin "
           << "To Track" << to << "." << std::endl;
        return ss.str();
    }
    if (!to) {
        ss << "Move Train No." << trainNum << " from track "
           << from << " to Target" << std::endl;
        return ss.str();
    }
    return std::string();
}

std::string TrainManager::InstructionToString(int track_num) {
    std::stringstream ss;
    if (track_num) {
        ss << "In this Case, you need at least " 
        << track_num << std::endl;
        return ss.str();
    }
    return std::string("You don\'t need any extra track to finish this task!\n");
}