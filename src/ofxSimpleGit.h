#pragma once
#include "ofMain.h"
#include <string>



namespace ofxGit
{
    class commandLineUtils
    {
    public:
        static int print(const std::string &text)
        {
            std::cout << text << std::flush;
            return text.size();
        }

        static void del(int size)
        {
            std::cout << std::string(size, '\b');
        }
    };

    class repository
    {
    public:
        explicit repository(const std::string &path) : _path(path) {}
        bool contains(const std::vector<string>& vec, string value) {
            return std::find(vec.begin(), vec.end(), value) != vec.end();
        }

        bool isRepository()
        {
            ofFile file(ofFilePath.join(_path, ".git")));
            return file.exists();
        }

        bool clone(const std::string &url)
        {
            std::string command = "git clone " + url + " " + _path;
            command += " --quiet";
            std::string result = ofSystem(command);
            return result.find("Cloning") != std::string::npos; // Check if cloning was successful based on the output
        }

        bool checkoutCommit(const std::string &hash)
        {
            std::string command = "cd " + _path + " && git checkout " + hash;
            std::string result = ofSystem(command);
            return result.find("Switched to commit") != std::string::npos; // Adjust based on actual output
        }

        bool checkoutTag(const std::string &name)
        {
            std::string command = "cd " + _path + " && git checkout tags/" + name;
            std::string result = ofSystem(command);
            return result.find("Switched to tag") != std::string::npos; // Adjust based on actual output
        }

        bool checkout(const std::string &ref)
        {
            std::string command = "cd " + _path + " && git checkout " + ref;
            command += " --quiet";
            std::string result = ofSystem(command);

            return result.find("Switched to branch") != std::string::npos; // Adjust based on actual output
        }

        std::string getCommitHash()
        {
            std::string command = "cd " + _path + " && git rev-parse HEAD";
            return ofSystem(command);
        }

        std::string getRemoteUrl(const std::string &name = "origin")
        {
            std::string command = "cd " + _path + " && git remote get-url " + name;
            return ofSystem(command);
        }

        std::string getLongHash(const std::string &hash)
        {
            std::string command = "cd " + _path + " && git rev-parse " + hash + " --long";
            return ofSystem(command);
        }

        bool isTag(const std::string &name)
        {
            // Construct the command to check for the tag
            std::string command = "cd " + _path + " && git tag -l";

            // Execute the command and capture the output
            std::string result = ofSystem(command);
            auto tags = ofSplitString(result, "\n");
            return contains(tags, name);
        }

        bool isCommit(const std::string &hash)
        {
            std::string command = "cd " + _path + " && git rev-parse --verify --quiet " + hash;
            std::string result = ofSystem(command);
            return !result.empty();
        }

    private:
        std::string _path;
    };

}; // namespace ofxGit
