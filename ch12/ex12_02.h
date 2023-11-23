/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-20 15:26:10
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::string;
using std::vector;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;

    StrBlob();
    StrBlob(std::initializer_list<string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { return data->push_back(t); }
    void pop_back();

    string &front();
    string &back();

    const string &front() const;
    const string &back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &str) const;
};

StrBlob::StrBlob() : data(std::make_shared<vector<string>>()) {}
StrBlob::StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &str) const
{
    if (i >= str.size())
        throw std::out_of_range(str);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}
