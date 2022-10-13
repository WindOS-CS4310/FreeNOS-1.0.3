

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
template <Size N> 
class PriorityQueue : public Container {
  public:
    PriorityQueue() {
        m_array = new Node[N];
        m_size = 0;
    }

    ~PriorityQueue() {
        delete[] m_array;
    }

    bool enq(Process* item, int pri) {
        if (m_size >= N) {
            return false;
        }

        m_array[m_size].value = item;
        m_array[m_size].pri = pri;
        m_size++;
        return true;
    }

    int peek() {
        int highest = 0;
        int index = 0;

        for (uint i = 0; i < m_size; i++) {
            if (highest < m_array[i].pri) {
                highest = m_array[i].pri;
                index = i;
            }
        }
        return index;
    }


    Process* deq() {
        int index = peek();
        Process* item = m_array[index].value;

        for (uint i = index; i < m_size - 1; i++) {
            m_array[i] = m_array[i+1];
        }
        m_size--;
        return item;
    }

    /**
     * Removes all items from the Queue.
     */
    virtual void clear()
    {
        m_size = 0;
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
        return m_size;
    }

  private:
    Node* m_array;
    uint m_size;
};

/**
 * @}
 * @}
 */

#endif /* __LIBSTD_PRIORITYQUEUE_H */
