/**
 * 💡 Question 1
 * À un problème de synchronisation
 */

/**
 * 💡 Question 2
 * 
 * sem_t libre;
 * sem_t occupe;
 * 
 * 🤖 Robot A:
 * P(libre);
 * Deposer_Ra();
 * V(occupe);
 * 
 * 🤖 Robot B:
 * P(occupe);
 * Prendre Rb();
 * V(libre);
 */

/**
 * 💡 Question 3
 * 
 * sem_t libre;
 * sem_t occupe;
 * 
 * 🔩 Deposer_Ra()
 * {
 *      P(exam);
 *      while( examiner() != LIBRE)
 *      {
 *          mutex_lock();
 *          Tourner();
 *          mutex_unlock();
 *      }
 *      P(libre);
 *      V(exam);
 *      Poser_la_piece();
 *      V(occupe);
 * }
 * 
 * 🔩 Prendre_Rb()
 * {
 *      P(exam);
 *      while( examiner() != OCCUPE)
 *      {
 *          mutex_lock();
 *          Tourner();
 *          mutex_unlock();
 *      }
 *      P(occupe);
 *      V(exam);
 *      Enlever_la_piece();
 *      V(libre);
 * }
 */