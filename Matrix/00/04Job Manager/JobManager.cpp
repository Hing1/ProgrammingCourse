#include <iostream>
#include "JobManager.h"

using std::cout;
using std::endl;

JobManager *JobManager::instance = NULL;

JobManager *JobManager::getInstance()
{
    if (instance == NULL)
    {
        instance = new JobManager;
    }
    return instance;
}
bool JobManager::deleteInstance()
{
    if (instance == NULL)
        return false;
    if (instance != NULL)
    {
        delete instance;
        instance = NULL;
        return true;
    }
}
void JobManager::addJob(int priority)
{
    if (jobFrontPointer == NULL)
    {
        jobFrontPointer = new Job(priority);
    }
    else
    {
        Job *pArr = jobFrontPointer;
        while (pArr->getNext() != NULL)
        {
            pArr = pArr->getNext();
        }
        Job *pArr2 = new Job(priority);
        pArr->setNext(pArr2);
    }
}
void JobManager::finishOneJob()
{
    if (jobFrontPointer != NULL)
    {
        Job *pArr = jobFrontPointer->getNext();
        delete jobFrontPointer;
        jobFrontPointer = pArr;
    }
}
void JobManager::sortJob()
{
    if (jobFrontPointer == NULL)
        return;
    Job *pArr = jobFrontPointer;
    if (pArr->getNext() == NULL)
        return;
    for (int i = 0; i < getNumOfJob() - 1; i++)
    {
        for (int j = 0; j < getNumOfJob() - 1 - i; j++)
        {
            if (pArr->getPriority() < pArr->getNext()->getPriority())
            {
                int temp1 = pArr->getId();
                int temp2 = pArr->getPriority();
                pArr->setId(pArr->getNext()->getId());
                pArr->getNext()->setId(temp1);
                pArr->setPriority(pArr->getNext()->getPriority());
                pArr->getNext()->setPriority(temp2);
            }
            if (pArr->getPriority() == pArr->getNext()->getPriority())
            {
                if (pArr->getId() > pArr->getNext()->getId())
                {
                    int temp1 = pArr->getId();
                    int temp2 = pArr->getPriority();
                    pArr->setId(pArr->getNext()->getId());
                    pArr->getNext()->setId(temp1);
                    pArr->setPriority(pArr->getNext()->getPriority());
                    pArr->getNext()->setPriority(temp2);
                }
            }
            pArr = pArr->getNext();
        }
        pArr = jobFrontPointer;
    }
}
void JobManager::printJob()
{
    if (jobFrontPointer == NULL)
    {
        cout << "empty!" << endl;
        return;
    }
    Job *pArr = jobFrontPointer;
    while (pArr != NULL)
    {
        cout << pArr->toString();
        pArr = pArr->getNext();
        if (pArr != NULL)
        {
            cout << "->";
        }
    }
    cout << endl;
}
int JobManager::getNumOfJob()
{
    int count = 0;
    Job *pArr = jobFrontPointer;
    while (pArr != NULL)
    {
        count++;
        pArr = pArr->getNext();
    }
    return count;
}
void JobManager::clear()
{
    Job *pArr = jobFrontPointer;
    while (pArr != NULL)
    {
        pArr = pArr->getNext();
        jobFrontPointer->setNext(NULL);
        delete jobFrontPointer;
        jobFrontPointer = pArr;
    }
}
JobManager::~JobManager()
{
    if (jobFrontPointer != NULL)
        clear();
}
JobManager::JobManager()
    : jobFrontPointer(NULL) {}
