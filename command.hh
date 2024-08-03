#ifndef COMMAND_HH
#define COMMAND_HH

#include "shapes.hh"

#include <vector>
#include <string>

using Shapes = std::vector<Shape*>;
using StringArgs = std::vector<std::string>;

class CommandReceiver;

class Command
{
protected:
    StringArgs m_args;
    CommandReceiver& m_receiver;
public:
    Command(CommandReceiver& r, const StringArgs& args);
    virtual bool execute() { return false; }
    virtual void printGeneralHelp() const = 0;
    virtual void printDetailedHelp() const = 0;
};

class CreateTriangleCmd : public Command
{
public:
    CreateTriangleCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override; 
};

class CreateRectangleCmd : public Command
{
public:
    CreateRectangleCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override; 
};

class CreateSquareCmd : public Command
{
public:
    CreateSquareCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override; 
};

class CreateListShapesCmd : public Command
{
public:
    CreateListShapesCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override; 
};

class DrawCmd : public Command
{
public:
    DrawCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override; 
};

class SetStyleCmd : public Command
{
public:
    SetStyleCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override; 
};

class HelpCmd : public Command
{
public:
    HelpCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override;
};

class ExitCmd : public Command
{
public:
    ExitCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override; 
};

class ClearCmd : public Command
{
public:
    ClearCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
    void printGeneralHelp() const override;
    void printDetailedHelp() const override;
};

class CommandReceiver
{
private:
    bool m_shouldExit;
    Shapes& m_shapes;
public:
    CommandReceiver(Shapes& shapes);
    bool shouldExit();
    void requestExit();
    void addShape(Shape* s);
    Shapes& getShapesVector();
};

StringArgs parseUserInput(const std::string& fullCmdStr);

Command* createCommand(CommandReceiver& cmdReceiver, const std::string& cmdName, const StringArgs& args);

#endif
