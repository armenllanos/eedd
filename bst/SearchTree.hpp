/*
  Filename   : SearchTree.hpp
  Author     : Gary M. Zoppetti
  Course     : CSCI 362
  Description: Binary search tree class, 
                 a basis for implementing associative ADTs
		 like set and map. 
*/

/************************************************************/
// Macro guard

#ifndef SEARCHTREE_HPP
#define SEARCHTREE_HPP

/************************************************************/
// System includes

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>

/************************************************************/
// Local includes

/************************************************************/
// Using declarations

using std::ostream;
using std::queue;



using std::cout;
using std::endl;


/************************************************************/

template<typename T>
struct Node
{
    using NodePtr = Node*;

    // TODO
    Node (const T& d = T ())
      : data (d), left (nullptr), right (nullptr), parent (nullptr)
    {
        // Initialize data, left, right, and parent in
        //   the member initialization list.
        // left, right, and parent should be set to nullptr.
        // The body of this constructor should be empty.
    }

    // TODO
    Node (const T& d, NodePtr l, NodePtr r, NodePtr p)
      : data (d), left (l), right (r), parent (p)
    {
        // Initialize data, left, right, and parent in
        //   the member initialization list.
        // The body of this constructor should be empty.
    }

    //**

    T data;
    NodePtr left;
    NodePtr right;
    NodePtr parent;
};

/************************************************************/

// Forward declaration
template<typename T>
class SearchTree;

/************************************************************/

template<typename T>
struct TreeIterator
{
    friend class SearchTree<T>;

    using Self = TreeIterator<T>;
    using NodePtr = Node<T>*;
    using ConstNodePtr = const Node<T>*;

    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;

    using value_type = T;
    using pointer = const T*;
    using reference = const T&;

    TreeIterator () : m_nodePtr ()
    {
    }

    explicit TreeIterator (ConstNodePtr n) : m_nodePtr (n)
    {
    }

    // TODO
    reference
    operator* () const
    {
        // Return the data associated with the referenced node.
        return m_nodePtr->data;
    }

    // Return address of node's data member.
    pointer
    operator->() const
    {
        return &*this;
    }

    // Pre-increment
    Self&
    operator++ ()
    {
        m_nodePtr = increment (m_nodePtr);

        return *this;
    }

    // Post-increment
    // TODO
    Self
    operator++ (int)
    {
        TreeIterator it = *this;
        m_nodePtr = increment (m_nodePtr);
        return it;
        // Increment iterator so it points to in-order successor.
        // Return appropriate iterator.
    }

    // Pre-decrement
    Self&
    operator-- ()
    {
        m_nodePtr = decrement (m_nodePtr);

        return *this;
    }

    // Post-decrement
    // TODO
    Self
    operator-- (int)
    {
        TreeIterator it = *this;
        m_nodePtr = decrement (m_nodePtr);
        return it;
        // Decrement iterator so it points to in-order predecessor.
        // Return appropriate iterator.
    }

    bool
    operator== (const Self& i) const
    {
        return m_nodePtr == i.m_nodePtr;
    }

    bool
    operator!= (const Self& i) const
    {
        return m_nodePtr != i.m_nodePtr;
    }

  private:
    // TODO
    static ConstNodePtr
    increment (ConstNodePtr n)
    {

        // Return in-order successor of "n".
        if (n->right != nullptr)
        {
            NodePtr aux = n->right;
            while (aux->left != nullptr)
            {
                aux = aux->left;
            }
            return aux;
        }
        while (n->parent != nullptr && n == n->parent->right)
        {
            n = n->parent;
        }
        return n->parent;
    }

    // TODO
    static ConstNodePtr
    decrement (ConstNodePtr n)
    {
        if (n->left != nullptr)
        {
            NodePtr aux = n->left;
            while (aux->right != nullptr)
            {
                aux = aux->right;
            }
            return aux;
        }
        while (n->parent != nullptr && n == n->parent->left)
        {
            n = n->parent;
        }
        return n->parent;
        // Return in-order predecessor of "n".
    }

    // FOR TESTING, otherwise would be PRIVATE
  public:
    ConstNodePtr m_nodePtr;
};

/************************************************************/

template<typename T>
class SearchTree
{
    friend class TreeIterator<T>;

  public:
    // DO NOT MODIFY type aliases!
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    using iterator = TreeIterator<T>;
    using const_iterator = TreeIterator<T>;

    // Header parent points to root of tree or is nullptr
    //   if the tree is empty.
    // Header left points to LARGEST node or is nullptr
    //   if the tree is empty.
    // Header right points to SMALLEST node or is nullptr
    //   if the tree is empty.
    // size represents the number of elements in the tree.
    SearchTree () : m_header (), m_size (0)
    {
        Node m_header;
        m_header.parent = nullptr;
        m_header.left = nullptr;
        m_header.right = nullptr;
    }

    // Copy constructor
    // TODO
    SearchTree (const SearchTree& t) : m_header (), m_size (t.m_size)
    {
        Node m_header;
        m_header.parent = nullptr;
        m_header.left = nullptr;
        m_header.right = nullptr;
        for (auto& i : t)
        {
            this->insert (i);
        }
    }

    ~SearchTree ()
    {
        clear ();
    }

    // Return whether the tree is empty.
    // TODO
    bool
    empty () const
    {
        return m_size == 0;
    }

    // Return the size.
    // TODO
    size_t
    size () const
    {
        return m_size;
    }

    int
    depth () const
    {
        return depth (m_header.parent);
    }

    // Return an iterator pointing to the smallest element.
    // TODO
    iterator
    begin ()
    {

        return iterator (minimum (m_header.right));
    }

    // TODO
    const_iterator
    begin () const
    {
        return iterator (minimum (m_header.right));
    }

    // Return an iterator pointing one beyond the last element,
    //   i.e. the header node.
    // TODO
    iterator
    end ()
    {
        return iterator (&m_header);
    }

    // TODO
    const_iterator
    end () const
    {
        return iterator (&m_header);
    }

    iterator
    find (const T& v) const
    {
        // Call private helper method
        ConstNodePtr n = findHelper (v);
        if (n == nullptr)
        {
            // Wasn't found so return end ()
            n = &m_header;
        }
        return iterator (n);
    }

    std::pair<iterator, bool>
    insert (const T& v)
    {
        NodePtr insertedNode = insert (v, m_header.parent, &m_header);
        bool inserted = insertedNode != nullptr;
        
        if (inserted)
        {
            // Update header right to point to smallest node
            if (m_header.right == nullptr || v < m_header.right->data)
                m_header.right = insertedNode;
            // Update header left to point to largest node
            if (m_header.left == nullptr || v > m_header.left->data)
                m_header.left = insertedNode;
        }

        return {iterator (insertedNode), inserted};
    }

    size_t
    erase (const T& v)
    {
        // Update header right to point to smallest node
        if (m_header.right != nullptr && v == m_header.right->data)
            m_header.right =
              const_cast<NodePtr> (iterator::increment (m_header.right));
        // Update header left to point to largest node
        else if (m_header.left != nullptr && v == m_header.left->data)
            m_header.left =
              const_cast<NodePtr> (iterator::decrement (m_header.left));

        bool erased = erase (v, m_header.parent);
        // If we erased the last value set header left and right to nullptr
        if (erased && empty ())
            m_header.left = m_header.right = nullptr;

        return erased ? 1 : 0;
    }

    // Delete all nodes, set header's parent, left, and right links to nullptr,
    //   and set size to 0. Utilizes a private, recursive "clear"
    //   declared below.
    // TODO
    void
    clear ()
    {
        if (m_header.parent != nullptr) {
            clear (m_header.parent);
        }

        m_size = 0;
        m_header.left = nullptr;
        m_header.right = nullptr;
        m_header.parent = nullptr;
    }

    void
    printInOrder (ostream& out) const
    {
        printInOrder (out, m_header.parent);
    }

    void
    printLevelOrder (ostream& out) const
    {
        printLevelOrder (out, m_header.parent);
    }

  private:
    using Node = struct Node<T>;
    using NodePtr = Node*;
    using ConstNodePtr = const Node*;

    int
    depth (ConstNodePtr r) const
    {
        if (r == nullptr)
            return -1;
        return std::max (depth (r->left), depth (r->right)) + 1;
    }

    // TODO
    NodePtr
    minimum (NodePtr r) const
    {
        if (r->left == nullptr)
        {
            return r;
        }
        else
        {
            return minimum (r->left);
        }
        // Return minimum node in tree rooted at "r".
    }

    // TODO
    NodePtr
    maximum (NodePtr r) const
    {
        if (r->right == nullptr)
        {
            return r;
        }
        else
        {
            return maximum (r->right);
        }
    }

    // TODO
    ConstNodePtr
    findHelper (const T& v) const
    {

        for (iterator i = this->begin (); i != this->end (); ++i)
        {
            if (*i == v)
            {
                // Return a pointer to the node that contains "v".
                return i.m_nodePtr;
            }
        }
        // Return a pointer to the node that contains "v".
        return nullptr;
    }

    // TODO
    NodePtr
    insert (const T& v, NodePtr& r, NodePtr parent)
    {
        NodePtr returnPtr = nullptr;
        if (r == nullptr)
        {
            returnPtr = new Node(v, nullptr, nullptr, parent);
            parent->parent = returnPtr;
        }
        if (r->data > v)
        {
            if (r->left != nullptr)
            {
                returnPtr = insert (v, r->left, r->parent);
            }
            else
            {
                returnPtr = new Node (v, nullptr, nullptr, r);
                r->left = returnPtr;
            }
        }
        else if (r->data < v)
        {
            if (r->right != nullptr)
            {
                returnPtr = insert (v, r->right, r->parent);
            }
            else
            {
                returnPtr = new Node (v, nullptr, nullptr, r);
                r->right = returnPtr;
            }
        }
        return returnPtr;
        // Insert "v" into the tree rooted at "r".
        // Use "parent" for recursion and setting the parent of the
        //   node containing "v".
    }

    // TODO
    bool
    erase (const T& v, NodePtr& r)
    {
        if (r == nullptr)
        {
            return false;
        }
        if (v < r->data)
        {
            return erase (v, r->left);
        }
        if (v > r->data)
        {
            return erase (v, r->right);
        }
        else
        {
            if (r->left == nullptr && r->right == nullptr)
            {
                clear (r);
                return true;
            }
            else if (r->left == nullptr)
            {
                NodePtr aux = minimum (r);
                r->data = aux->data;
                return erase (aux->data, aux);
            }
            else
            {
                NodePtr aux = maximum (r);
                r->data = aux->data;
                return erase (aux->data, aux);
            }
        }

        // Erase "v" from the tree rooted at "r".
        // Return whether the erase succeeded or not.
    }

    // TODO
    void
    clear (NodePtr r)
    {

        if (r->left != nullptr)
        {
            clear (r->left);
        }
        if (r->right != nullptr)
        {
            clear (r->right);
        }
        delete r;

        // Delete all nodes in the tree rooted at "r".
    }

    void
    printInOrder (ostream& out, NodePtr r) const
    {
        if (r != nullptr)
        {
            printInOrder (out, r->left);
            out << r->data << " ";
            printInOrder (out, r->right);
        }
    }

    // TODO
    // FIXME: This routine is INCORRECT and is only meant to
    //   show you some techniques you MAY want to employ.
    // Rewrite this method to output elements in the form required
    //   by the operator<< below.
    void
    printLevelOrder (ostream& out, NodePtr r) const
    {
        if (r != nullptr) {
      

            queue<NodePtr> q = levelOrderChildren(r);

            out << r->data << " ";
            while (!q.empty ())
            {
                r = q.front ();
                q.pop ();
                out << r->data << " ";
            }
        }
    }

    queue<NodePtr>
    levelOrderChildren (NodePtr r) const
    {
        queue<NodePtr> qLeft;
        queue<NodePtr> qRight;
        
        if (r == nullptr)
        {
            return qLeft;
        }
        
        if (r->left != nullptr)
        {
            qLeft.push (r->left);
            qLeft = levelOrderChildren (r->left);
        }
        
        if (r->right != nullptr)
        {
            qLeft.push (r->right);
            qRight = levelOrderChildren (r->right);
        }
        
        while (!qRight.empty ())
        {
            qLeft.push (qRight.front ());
            qRight.pop ();
        }

        return qLeft;
    }

  private:
    Node m_header;
    size_t m_size;
};

/************************************************************/

// Output tree as [ e1 e2 e3 ... en ]
//   with a '|' to indicate the end of a level,
//   and a '-' to indicate a missing node.
// E.g., the tree
//       4
//    2     7
//         6
// should be printed EXACTLY like so: [ 4 | 2 7 | - - 6 - ]
// ONLY print the levels that exist, and ensure each level contains
//   2^k entries (a T object or "-"), where "k" is the level number.
template<typename T>
ostream&
operator<< (ostream& out, const SearchTree<T>& tree)
{
    out << "[ ";
    // For the version you submit, ensure you are using "printLevelOrder"!
    // You may find "printInOrder" useful for early testing, since it's
    //   been written for you.
    //tree.printInOrder (out);
    tree.printLevelOrder (out);
    out << "]";

    return out;
}

/************************************************************/

#endif

/************************************************************/
