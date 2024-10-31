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
    static void registerUpdateFunction(const std::function<void(double deltaTime)>& updateFunction);
private:
    static inline std::mutex mutex_;
    static inline std::vector<std::function<void(double deltaTime)>> updateFunctions_;
    static inline std::vector<std::function<void(double deltaTime)>> updateFunctionsToAdd_;
    static inline std::vector<std::chrono::time_point<std::chrono::system_clock>> updateTimePoints_;
};



#endif //UPDATECONTROLLER_H
