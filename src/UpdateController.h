//
// Created by eal on 10/31/24.
//

#ifndef UPDATECONTROLLER_H
#define UPDATECONTROLLER_H
#include <functional>
#include <memory>
#include <shared_mutex>


class UpdateController
{
public:
    static void beginUpdateLoop();
    static void registerUpdateFunction(const std::function<void(float deltaTime)>& updateFunction);
private:
    static inline std::mutex mutex_;
    static inline std::vector<std::function<void(float deltaTime)>> updateFunctions_;
    static inline std::vector<std::function<void(float deltaTime)>> updateFunctionsToAdd_;
};



#endif //UPDATECONTROLLER_H
