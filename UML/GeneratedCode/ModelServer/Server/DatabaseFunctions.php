<?php

namespace Server;

/**
 * @author Zsolt German
 */
class DatabaseFunctions
{
    /**
     *
     */
    public function __construct()
    {
    }

    /**
     * @param string $username
     * @param string $password
     */
    public function addUser($username, $password):void
    {
        // TODO: implement here
    }

    /**
     *
     */
    public function removeUser():void
    {
        // TODO: implement here
    }

    /**
     * @param string $username
     * @param string $password
     * @param string $ip
     * @param int $port
     * @param string $publicKey
     * @return boolean
     */
    public function login($username, $password, $ip, $port, $publicKey):boolean
    {
        // TODO: implement here
        return false;
    }

    /**
     * @param string $ip
     */
    public function refreshStatus($ip):void
    {
        // TODO: implement here
    }

    /**
     *
     */
    public function logout():void
    {
        // TODO: implement here
    }

    /**
     *
     */
    public function getContacts():void
    {
        // TODO: implement here
    }

    /**
     * @param string $search
     */
    public function findContacts($search):void
    {
        // TODO: implement here
    }

    /**
     * @param string $username
     */
    public function addContact($username):void
    {
        // TODO: implement here
    }

    /**
     * @param string $username
     */
    public function acceptContact($username):void
    {
        // TODO: implement here
    }

    /**
     * @param string $username
     */
    public function blockContact($username):void
    {
        // TODO: implement here
    }

    /**
     * @param string $username
     */
    public function getConnectionData($username):void
    {
        // TODO: implement here
    }
}
