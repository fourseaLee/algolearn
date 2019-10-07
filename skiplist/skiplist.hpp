#ifndef SKIPLIST_HPP
#define SKIPLIST_HPP
template<typename K, typename V>
class SkipList;
class NodeSkipList
{
    friend class SkipList<K, V>;
public:
    NodeSkipList() {}

    NodeSkipList(K k, V v);

    ~NodeSkipList();

public:
    K getKey() const;

    V getValue() const;

private:
    
    K key_;

    V value_;

    NodeSkipList<K, V> ** forward_;

    int node_level_;

};

template<typename K, typename V>
NodeSkipList<K, V>::NodeSkipList(const K k, const V v)
{
    key_ = k;

    value_ = value;
}

template<typename K, typename V>
NodeSkipList<K, V>::~NodeSkipList()
{
    delete[] forward_;
}

template<typename K, typename V>
K NodeSkipList<K, V>::getKey() const
{
    return key_;
}

template<typename K, typename V>
V NodeSkipList<K, V>::getValue() const
{
    return value_;
}


template<typename K, typename V>
class SkipList
{
public:
    SkipList(K footer_key)
    {
        createList(footer_key);
    }

    ~SkipList()
    {
        freeList();
    }

    NodeSkipList<K, V> *find(K key) const;

    bool insert(K key, V value);

    bool remove(K key, V &value);

    int size()
    {
        return node_count_;
    }

    int getLevel()
    {
        return level_;
    }

private:
    
    void createList(K footerKey);

    void freeList();

    void createNode(int level, NodeSkipList<K, V> *& node);

    void createNode(int level, NodeSkipList<K, V> *& node, K key, V value);

    int getRandomLevel();

    void dumpAllNodes();

    void dumpNodeDetail(NodeSkipList<K, V> *node, int node_level);


private:
    
    int level_;

    NodeSkipList<K, V> *header_;
    NodeSkipList<K, V> *footer_;

    size_t node_count_;
    static const int MAX_LEVEL_ = 16;

};

template<typename K, typename V>
void SkipList<K, V>::createList(K footer_key)
{
    createNode(0, footer_);
    footer_->key_ = footer_key;
    this->level_ = 0;

    createNode(MAX_LEVEL_, header_);

    for(int i = 0; i < MAX_LEVEL_; ++i)
    {
        header_->forward[i] = footer;
    }

    node_count_ = 0;
}


template<typename K, typename V>
void SkipList<K, V>::createNode(int level, NodeSkipList<K, V> *&node)
{
    node = new NodeSkipList<K, V>(NULL, NULL);

    node->forward_ = new NodeSkipList<K, V> *[level + 1];

    node->node_level_ = level;

}

template<typename K, typename V>
void SkipList<K, V>::freeList()
{
    NodeSkipList<K, V> *p = header_;

    NodeSkipList<K, V> *q;
    while(p != NULL)
    {   
        q = p->forward_[0];
        delete p;
        p = q;
    }
    delete p;
}

template<typename K, typename V>
NodeSkipList<K, V> SkipList<K, V>::find(const K key)const
{
    NodeSkipList<K, V> *node = header_;

    for (int i = level_; i >= 0; --i)
    {
        while ((node->forward_[i]->key_ < key))
        {
            node = *(node->forward_ + i);
        }
    }

    node = node->forward_[0];

    if (node->key_ == key)
    {
        return node;
    }
    else 
    {
        return nullptr;
    }
}

template<typename K, typename V>
bool SkipList<K, V>::insert(K key, V value)
{
    NodeSkipList<K, V> *update[MAX_LEVEL_];
    
    NodeSkipList<K, V> *node = header_;

    for(int i = level_; i >= 0; --i)
    {
        while ((node->forward_[i])->key_ < key)
        {
            node = node->forward_[i];
        }
        update[i] = node;
    }

    node = node->forward_[0];

    if (node->key_ == key)
    {
        return false;
    }

    int node_level = getRandomLevel();

    if(node_level > level_)
    {
        node_level = ++ level_;
        update[node_level] = header_;
    }

    NodeSkipList<K, V> *new_node;

    createNode(node_level, new_node, key, value);

    for(int i = node_level; i >= 0; --i)
    {
        node = update[i];

        newNode->forward_[i] = node->forward_[i];

        node->forward_[i] = new_node;
    }

    ++ node_count_;

    return true;
}

template<typename K, typename V>
void SkipList<K, V>::dumpAllNodes()
{
    NodeSkipList<K, V>* tmp = header_;

    while(tmp->forward_[0] != footer_)
    {
        tmp = tmp->forward_[0];

        dumpNodeDetail(tmp, tmp->node_level_);

    }
}
template<typename K, typename V>
void SkipList<K, V>::dumpNodeDetail(NodeSkipList<K, V> *node, int node_level)
{
    if (node == nullptr)
    {
        return;
    }


}

template<typename K, typename V>
bool SkipList<K, V>::remove(K key, V &value)
{
    NodeSkipList<K, V> *update[MAX_LEVEL];
    NodeSkipList<K, V> *node = header_;

    for(int i = level_ ; i >= 0; --i)
    {
        while((node->forward_[i]->key_ < key))
        {
            node = node->forward_[i];
        }

        update[i] = node;
    }

    node = node->forward_[0];

    if(node->key_ != key)
    {
        return false;
    }

    value = node->value_;

    for(int i = 0; i < level_; ++i)
    {
        if(update[i]->forward_[i] != node)
        {
            break;
        }
        update[i]->forward_[i] = node->forward_[i];
    }

    delete node;

    while (level > 0 && header_->forward_[level] == footer)
    {
        --level;
    }

    --node_count_;

    return true;
}
template<typename K, typename V>
int SkipList<K, V>::getRandowLevel()
{
    int level = node_count_ % MAX_LEVEL_;//rand(0,MAX_LEVEL_)

    if (level == 0)
    {
        level = 1;
    }

    return level;
}
#endif
