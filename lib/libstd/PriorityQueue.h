

#ifndef __LIBSTD_PRIORITYQUEUE_H
#define __LIBSTD_PRIORITYQUEUE_H

#include "Types.h"
#include "Macros.h"
#include "Container.h"

struct Node {
    Process* value;
    int pri;
};

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libstd
 * @{
 */

/**
 * Array of items as a Priority Queue
 */
template <class T, Size N> class PriorityQueue : public Container
{
  public:

    /**
     * Default constructor
     */
    PriorityQueue() {
        clear();
        m_array = new Node[N];
    }

    bool enq(Process* item, int pri) {
        if (m_count >= N) {
            return false;
        }

        m_size++;
        m_count++;

        /*Node n* = new Node();
        n.value = item;
        n.pri = pri;*/
        
        m_array[m_size].value = item;
        m_array[m_size].pri = pri;
        return true;
    }

    int peek() {
        int highest = 8;
        int index = -1;

        for (Size i = 0; i <= m_count; i++) {
            if (highest < m_array[i].pri) {
                highest = m_array[i].pri;
                index = i;
            } else {
                index = i;
            }
        }
        return index;
    }

    /**
     * Remove item from the tail of the Queue.
     *
     * @return Item T
     *
     * @note Do not call this function if the Queue is empty
     */
    Process* deq() {
        int index = peek();
        Process* item = m_array[index].value;
        for (Size i = index; i < m_count; i++) {
            m_array[i] = m_array[i+1];
        }
        m_count--;
        return item;
    }

    /**
     * Removes all items from the Queue.
     */
    virtual void clear()
    {
        m_size = -1;
        m_count = 0;
    }

    /**
     * Returns the maximum size of this Queue.
     *
     * @return size The maximum size of the Queue.
     */
    virtual Size size() const
    {
        return N;
    }

    /**
     * Returns the number of items in the Queue.
     *
     * @return Number of items in the Queue.
     */
    virtual Size count() const
    {
        return m_count;
    }

  private:
    Node* m_array;
    uint m_size;
    uint m_count;
};

/**
 * @}
 * @}
 */

#endif /* __LIBSTD_PRIORITYQUEUE_H */
