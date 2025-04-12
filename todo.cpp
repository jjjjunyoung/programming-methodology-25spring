#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    size=0;
    for(int i=0; i<MAX_TASKS; i++){
        tasks[i]=nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i=0; i<MAX_TASKS; i++){
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
    size=0;
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    if (str == nullptr) return 0;

    int i=0;
    while (str[i]!='\0'){
        i++;
    }
    return i;
}

void TodoList::string_copy(char* dest, const char* src) const {
    int i=0;
    while (src[i]!='\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size == MAX_TASKS){
        throw AddTooManyTasksThrows();
    }
    else{
        int len = string_length(task);
        tasks[size]=new char[len+1];
        string_copy(tasks[size], task);
        size++;
    }
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index<0 || index>size+1){
        throw RemoveInvalidIndexThrows();
    }
    delete[] tasks[index];
    for (int i=index+1;i<size;i++){
        tasks[i-1]=tasks[i];
    }
    tasks[size-1]=nullptr;
    size--;

}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    return const_cast<const char**>(tasks);
}