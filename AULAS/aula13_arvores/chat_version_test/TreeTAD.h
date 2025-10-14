#pragma once
#include <iostream>
#include <vector>
#include <string>

class TreeTAD {
public:
    virtual void addChild(TreeTAD* tree) = 0;
    virtual void addChild(int index, TreeTAD* tree) = 0;
    virtual TreeTAD* removeChild(int index) = 0;
    virtual TreeTAD* getChild(int index) = 0;
    virtual int childrenCount() = 0;
    virtual int getItem() = 0;
    virtual TreeTAD* getParent() = 0;
    virtual void print() = 0;
    virtual ~TreeTAD() {}
};

class Tree : public TreeTAD {
private:
    Tree* parent;
    int item;
    std::vector<Tree*> children;

public:
    Tree(int value) : parent(nullptr), item(value) {}
    ~Tree() { for(Tree* c : children) delete c; }

    void addChild(TreeTAD* tree) override {
        Tree* t = dynamic_cast<Tree*>(tree);
        if (t) { t->parent = this; children.push_back(t); }
    }

    void addChild(int index, TreeTAD* tree) override {
        if (index < 0 || index > (int)children.size()) return;
        Tree* t = dynamic_cast<Tree*>(tree);
        if (t) { t->parent = this; children.insert(children.begin() + index, t); }
    }

    TreeTAD* removeChild(int index) override {
        if (index < 0 || index >= (int)children.size()) return nullptr;
        Tree* removed = children[index];
        removed->parent = nullptr;
        children.erase(children.begin() + index);
        return removed;
    }

    TreeTAD* getChild(int index) override {
        if (index < 0 || index >= (int)children.size()) return nullptr;
        return children[index];
    }

    int childrenCount() override { return children.size(); }
    int getItem() override { return item; }
    TreeTAD* getParent() override { return parent; }

    void print() override {
        printRecursive("", true);
    }

private:
    void printRecursive(const std::string& prefix, bool isLast) {
        std::cout << prefix;

        if (parent != nullptr) {
            std::cout << (isLast ? "└─" : "├─");
        }

        std::cout << item << std::endl;

        for (size_t i = 0; i < children.size(); ++i) {
            children[i]->printRecursive(prefix + (parent != nullptr ? (isLast ? "  " : "│ ") : ""), i == children.size() - 1);
        }
    }
};
