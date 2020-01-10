#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__
#include "gtest/gtest.h"
#include "../src/Execute.hpp"
#include "../src/ExecuteAND.hpp"
#include "../src/ExecuteOR.hpp"
#include "../src/ExecuteSEMI.hpp"
#include "../src/InputRedirect.hpp"
#include "../src/OutputRedirect.hpp"
#include "../src/OutputRedirect2.hpp"
#include "../src/piping.hpp"

TEST(ExecuteTest, ExecuteLS) {
	vector<string> str1 = {"ls", "-a"};
	Execute* exec = new Execute(str1);
	EXPECT_EQ(exec->execute(), true);
}

TEST(ExecuteCmdTest, ExecuteEcho) {
	vector<string> str2 = {"echo", "hello world"};
	Execute* execEcho = new Execute(str2);
	EXPECT_EQ(execEcho->execute(), true);
}

TEST(ExecuteCmdTest, ExecuteEch) {  //test that SHOULD fail but still return true; improper testing of "echo"
	vector<string> str3 = {"ech", "hello world"};
	Execute* execEch = new Execute(str3);
	EXPECT_EQ(execEch->execute(), false);
}

TEST(ExecuteCmdTest, ExecuteGitStatus) {
	vector<string> str4 = {"git", "status"};
	Execute* execGitStat = new Execute(str4);
	EXPECT_EQ(execGitStat->execute(), true);
}

TEST(ExecuteCmdTest, Clear) {
        vector<string> str4 = {"clear"};
        Execute* execClr = new Execute(str4);
        EXPECT_EQ(execClr->execute(), true);
}

TEST(ExecuteCmdTest, ExecuteGitBranch) {
        vector<string> str4 = {"git", "branch"};
        Execute* execBrch = new Execute(str4);
        EXPECT_EQ(execBrch->execute(), true);
}

TEST(ExecuteConTest, ExecuteConAnd) {
	vector<string> executeAnd1;
	vector<string> executeAnd2;
	executeAnd1.push_back("echo");
	executeAnd1.push_back("hello");
	executeAnd2.push_back("echo");
	executeAnd2.push_back("world");
	Execute* execConAnd1 = new Execute(executeAnd1);
	Execute* execConAnd2 = new Execute(executeAnd2);
	ExecuteAND* execAndConnector = new ExecuteAND(execConAnd1, execConAnd2);
	EXPECT_EQ(execAndConnector->execute(), true);
}

TEST(ExecuteConTest, ExecuteConOr) {
	vector<string> executeOr1;
	vector<string> executeOr2;
        executeOr1.push_back("echo");
	executeOr1.push_back("hello");
	executeOr2.push_back("echo");
	executeOr2.push_back("world");
	Execute* execConOr1 = new Execute(executeOr1);
	Execute* execConOr2 = new Execute(executeOr2); 
	ExecuteOR* execOrConnector = new ExecuteOR(execConOr1, execConOr2);
	EXPECT_EQ(execOrConnector->execute(), true);
}

TEST(ExecuteConTest, ExecuteConSemi) {
        vector<string> executeSemi1;
	vector<string> executeSemi2;
        executeSemi1.push_back("echo");
	executeSemi1.push_back("hello");
	executeSemi2.push_back("echo");
	executeSemi2.push_back("world");
	Execute* execConSemi1 = new Execute(executeSemi1);
        Execute* execConSemi2 = new Execute(executeSemi2);
	ExecuteSEMI* execSemiConnector = new ExecuteSEMI(execConSemi1, execConSemi2); 
        EXPECT_EQ(execSemiConnector->execute(), true);
}

TEST(ExecuteCmdTest, ExecuteTest) {
        vector<string> executeTestFunc;
	executeTestFunc.push_back("test");
	executeTestFunc.push_back("-f");
	executeTestFunc.push_back("src/main.cpp");
        Execute* execTest = new Execute(executeTestFunc);
        EXPECT_EQ(execTest->execute(), true);
}

TEST(ExecParseTest, ParserTest1) {
        vector<string> executeMultConnectors1;
        vector<string> executeMultConnectors2;
        vector<string> executeMultConnectors3;
        vector<string> executeMultConnectors4;
        executeMultConnectors1.push_back("test");
        executeMultConnectors1.push_back("-d");
        executeMultConnectors1.push_back("src");
        executeMultConnectors2.push_back("echo");
        executeMultConnectors2.push_back("“unit_tests/ directory missing, check submission instruction section of the specifications");
        Execute* execPrsTest1 = new Execute(executeMultConnectors1);
        Execute* execPrsTest2 = new Execute(executeMultConnectors2);
        ExecuteOR* execParseTest3 = new ExecuteOR(execPrsTest1, execPrsTest2);
        EXPECT_EQ(execParseTest3->execute(), true);
}

TEST(ExecParseTest, ParserTest2) {
        vector<string> executeMultConnectors1;
	vector<string> executeMultConnectors2;
	vector<string> executeMultConnectors3;
	vector<string> executeMultConnectors4;
        executeMultConnectors1.push_back("echo");
	executeMultConnectors1.push_back("A");
	executeMultConnectors2.push_back("echo");
	executeMultConnectors2.push_back("B");
	executeMultConnectors3.push_back("echo");
	executeMultConnectors3.push_back("C");
	executeMultConnectors4.push_back("echo");
	executeMultConnectors4.push_back("D");	
        Execute* execPrsTest1 = new Execute(executeMultConnectors1);
	Execute* execPrsTest2 = new Execute(executeMultConnectors2);
	Execute* execPrsTest3 = new Execute(executeMultConnectors3);
	Execute* execPrsTest4 = new Execute(executeMultConnectors4);
       	ExecuteAND* execParseTest1 = new ExecuteAND(execPrsTest1, execPrsTest2);
	ExecuteAND* execParseTest2 = new ExecuteAND(execPrsTest3, execPrsTest4);
	ExecuteOR* execParseTest3 = new ExecuteOR(execParseTest1, execParseTest2);
	EXPECT_EQ(execParseTest3->execute(), true);
}

/*TEST(InputRedTest, InputTest) {
	vector<string> executeInputRed;
	executeInputRed.push_back("cat");
	Execute* executeInRed = new Execute(executeInputRed);
	InputRedirect* execInRed = new InputRedirect(executeInRed, unit_tests/testingRedirect.txt);
	EXPECT_EQ(execInRed->execute(), true);
}

TEST(OutputRedTest, OutputTest) {
        vector<string> executeOutputRed;
        executeInputRed.push_back("cat");
        Execute* executeInRed = new Execute(executeInputRed);
        InputRedirect* execInRed = new InputRedirect(executeInRed, unit_tests/testingRedirect.txt);
        EXPECT_EQ(execInRed->execute(), true);
}*/

TEST(PipingTest, PipingTest) {
        vector<string> executePiping1;
	vector<string> executePiping2;
        executePiping1.push_back("cat");
	executePiping1.push_back("testingRedirect.txt");
	executePiping2.push_back("tr");
	executePiping2.push_back("a-z");
	executePiping2.push_back("A-Z");
        Execute* executePipe1 = new Execute(executePiping1);
	Execute* executePipe2 = new Execute(executePiping2);
        Piping* execAllPipes = new Piping(executePipe1, executePipe2);
        EXPECT_EQ(execAllPipes->execute(), false);
}



#endif
