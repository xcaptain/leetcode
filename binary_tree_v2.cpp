#include <iostream>

class BSTNode
{
  public:
    BSTNode();
    BSTNode(int data);
    ~BSTNode();
    void insert(int data);
    bool contains(int data);

  private:
    int data;
    BSTNode *left;
    BSTNode *right;
};

BSTNode::BSTNode()
{
    this->data = NULL;
    this->left = nullptr;
    this->right = nullptr;
}

BSTNode::BSTNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

void BSTNode::insert(int data)
{
    if (this->data == NULL)
    {
        this->data = data;
    }
    else
    {
        if (data <= this->data)
        {
            if (this->left == nullptr)
            {
                this->left = new BSTNode(data);
            }
            else
            {
                this->left->insert(data);
            }
        }
        else
        {
            if (this->right == nullptr)
            {
                this->right = new BSTNode(data);
            }
            else
            {
                this->right->insert(data);
            }
        }
    }
}

BSTNode::~BSTNode()
{
    this->data = NULL;
    this->left = this->right = nullptr;
}

bool BSTNode::contains(int data)
{
    BSTNode* ptr = this;
    while (ptr->data != NULL) {
        if (ptr->data == data) {
            return true;
        } else if (data < ptr->data) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    return false;
}


int main(int argc, char const *argv[])
{
    BSTNode* root = new BSTNode(4);
    root->insert(1);
    root->insert(6);
    std::cout << root->contains(3) << std::endl;
    return 0;
}
