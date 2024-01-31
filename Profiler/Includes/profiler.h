#pragma once 

#include <iostream>
#include <fstream>
#include <chrono>

// struct to hold the profiling result (thread id, start time, end time)
struct ProfileResult{ 
    std::string name;
    long long Start, End;
    uint32_t threadID;
};

// profiling session 
struct InstrumentationSession{
    std::string name;
};

// the actual profiler
class Instrumentor{
private:
    InstrumentationSession* m_CurrentSession;
    std::ofstream m_OutputStream;
    int m_ProfileCount;

public:
    Instrumentor();
    // starts a new profile session, writes the necessary headers
    void BeginSession(const std::string& name, const std::string& filepath = "results.json");

    // ends the session, writes the necessary footers
    void EndSession();

    // do I really have to explain these? 
    void WriteProfile(const ProfileResult& result);
    void WriteHeader();
    void WriteFooter();

    // returns the current instance of the instrumentor
    static Instrumentor& Get();
};

// helper timer class for benchmarking
class InstrumentationTimer {
public:
    InstrumentationTimer(const char* name);
    ~InstrumentationTimer();
    void Stop();
private:
    const char* m_Name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
    bool m_Stopped;
};

// macro definitions for benchmarking
#ifdef BENCHMARK
    #define PROFILE(name) InstrumentationTimer timer##__LINE__(name)
    #define PROFILE_FUNCTION() PROFILE(__PRETTY_FUNCTION__)
    #define BEGIN_PROFILE_SESSION(filepath) Instrumentor::Get().BeginSession(__PRETTY_FUNCTION__, filepath)
    #define END_PROFILE_SESSION() Instrumentor::Get().EndSession()
#else 
    #define PROFILE(name)
    #define PROFILE_FUNCTION()
    #define BEGIN_PROFILE_SESSION() 
    #define END_PROFILE_SESSION() 
#endif